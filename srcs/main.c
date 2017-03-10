/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 10:45:49 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/10 10:29:06 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		test_access(char **path, int size)
{
	int retval;
	int i;

	i = 0;
	retval = -1;
	while (i < size)
	{
		if (access(path[i], F_OK) == 0)
			retval = i;
		i++;
	}
	return (retval);
}

void	env(char ***env, char **input)
{
	if (input[1] == NULL)
		ft_print_array(*env);
}

void	what_cmd(char **input, char ***envcpy, int size, char **tmp_path)
{
	int ok;

	ok = 0;
	if (ft_strcmp(input[0], "cd") == 0)
		cmd_cd(input, envcpy);
	else if (ft_strcmp(input[0], "env") == 0)
		env(envcpy, input);
	else if (ft_strcmp(input[0], "setenv") == 0)
		command_setenv(input, envcpy);
	else if (ft_strcmp(input[0], "unsetenv") == 0)
		command_unsetenv(input, envcpy);
	else if (ft_strcmp(input[0], "echo") == 0)
		cmd_echo(input);
	else if (ft_strcmp(input[0], "help") == 0)
		disp_help();
	else
	{
		if (ft_getenv("PATH", *envcpy) == -1)
			ft_printf("Minishell: Command not found: %s\n", input[0]);
		else
		{
			ok = test_access(tmp_path, size);
			if (ok == -1)
				ft_printf("Minishell: Command not found: %s\n", input[0]);
			else
				cmd_exec(tmp_path[ok], input, *envcpy);
		}
	}
}

int		ft_default_env(char ***env)
{
	struct passwd	*passwd;

	if (!(*env = (char **)ft_memalloc(sizeof(char*))))
		return (FALSE);
	*env = ft_setenv("PATH", DPATH, *env);
	if ((passwd = getpwuid(getuid())))
	{
		*env = ft_setenv("USER", passwd->pw_name, *env);
		*env = ft_setenv("HOME", passwd->pw_dir, *env);
	}
	*env = ft_setenv("SHLVL", "1", *env);
	return (TRUE);
}

void	direct_path(char **input, char ***envcpy)
{
	(void)envcpy;
	(void)input;
	if (access(input[0], F_OK) == 0)
		cmd_exec(input[0], input, *envcpy);
	else
		ft_printf("Minishell: Error: Command not found\n");
}

size_t		ft_tabcount(void **tab)
{
	size_t	p;

	p = 0;
	while (tab[p])
		p++;
	return (p + 1);
}

static char		**clear_bintab(char **tab, size_t size)
{
	while (size--)
		if (tab[size])
			free(tab[size]);
	free(tab);
	return (NULL);
}

static char		**get_bintab(char **path_tab, size_t size,
		const char *binstr)
{
	const size_t	fullsize = size;
	char			**tab;

	if (!(tab = malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	tab[size] = NULL;
	while (size--)
	{
		tab[size] = ft_strmjoin(3, path_tab[size], "/", binstr);
		if (!tab[size])
			return (clear_bintab(tab, fullsize));
	}
	return (tab);
}

int		main(int argc, char **argv, char **environ)
{
	char *line;
	char **input;
	char **envcpy;
	char **path;
	char **full_path;
	char cwd[1024];
	size_t path_size;
	t_data data;

	(void)argc;
	(void)argv;
	signal(SIGINT, sig_handle);
	if (!environ || !environ[0] || !(envcpy = ft_tabdup(environ)))
		if (!ft_default_env(&envcpy))
			return (ft_printf("ERROR"));
	path = path_parser(envcpy, &data);
	getcwd(cwd, sizeof(cwd));
	envcpy = ft_setenv("PWD", cwd, envcpy);
	ft_printf("{:blue}[{:lred}Minishell{:blue}] {:lgreen}➜{:reset} ");
	while (get_next_line(0, &line))
	{
		if (ft_strcmp(line, "\n") > 0)
		{
			input = ft_str_to_tab_sep(line, ' ', 0);
			path_size = ft_tabcount((void**)(size_t)path);
			if (!(full_path = get_bintab(path, path_size, input[0])))
				ft_printf("Error");
			if (ft_strcmp(line, "exit") == 0)
			{
				free(line);
				exit(EXIT_SUCCESS);
			}
			if (ft_strchr(input[0], '/') != NULL)
				direct_path(input, &envcpy);
			else
				what_cmd(input, &envcpy, data.nb_bin, full_path);
			clear_bintab(full_path, path_size);
			ft_free_array(input);
		}
		ft_printf("{:blue}[{:lred}MiniShell{:blue}] {:lgreen}➜{:reset} ");
	}
	free(line);
	clear_bintab(full_path, path_size);
	return (0);
}
