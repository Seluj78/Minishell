/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 10:45:49 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/10 13:41:03 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			test_access(char **path, int size)
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

void		env(char ***env, char **input)
{
	if (input[1] == NULL)
		ft_print_array(*env);
}

int			ft_default_env(char ***env)
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

static void	main2(t_data *data)
{
	data->input = ft_strsplit(data->line, ' ');
	data->path_size = ft_tabcount((void**)(size_t)data->path);
	if ((!(data->full_path = get_bintab(data->path, data->path_size, \
						data->input[0]))) && (!data->input))
		ft_printf("Error");
	if (ft_strcmp(data->line, "exit") == 0)
	{
		free(data->line);
		exit(EXIT_SUCCESS);
	}
	if (ft_strchr(data->input[0], '/') != NULL)
		direct_path(data->input, &data->envcpy);
	else
		what_cmd(data->input, &data->envcpy, data->nb_bin, data->full_path);
	clear_bintab(data->full_path, data->path_size);
	ft_free_array(data->input);
}

int			main(int argc, char **argv, char **environ)
{
	t_data data;

	(void)argc;
	(void)argv;
	signal(SIGINT, sig_handle);
	if (!environ || !environ[0] || !(data.envcpy = ft_tabdup(environ)))
		if (!ft_default_env(&data.envcpy))
			return (ft_printf("ERROR"));
	data.path = path_parser(data.envcpy, &data);
	getcwd(data.cwd, sizeof(data.cwd));
	data.envcpy = ft_setenv("PWD", data.cwd, data.envcpy);
	ft_printf("{:blue}[{:lred}Minishell{:blue}] {:lgreen}➜{:reset} ");
	while (get_next_line(0, &data.line))
	{
		if (ft_strcmp(data.line, "\n") > 0)
			main2(&data);
		ft_printf("{:blue}[{:lred}MiniShell{:blue}] {:lgreen}➜{:reset} ");
	}
	free(data.line);
	clear_bintab(data.full_path, data.path_size);
	return (0);
}
