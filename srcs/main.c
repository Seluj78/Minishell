/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 10:45:49 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/07 16:00:08 by jlasne           ###   ########.fr       */
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

void	env(char ***env, char **input, char **tmp_path, int size)
{
		(void)tmp_path;
		(void)size;

		if (input[1] == NULL)
				ft_print_array(*env);
}

void	what_cmd(char **input, char ***envcpy, int size, char **tmp_path)
{
		//OPTI : tableau de Pointeur sur fonctions
		int ok;

		ok = 0;
		if (ft_strcmp(input[0], "cd") == 0)
				cmd_cd(input, envcpy);
		else if (ft_strcmp(input[0], "env") == 0)
				env(envcpy, input, tmp_path, size);
		else if (ft_strcmp(input[0], "setenv") == 0)
				command_setenv(input, envcpy);
		else if (ft_strcmp(input[0], "unsetenv") == 0)
				command_unsetenv(input ,envcpy);
		else if (ft_strcmp(input[0], "echo") == 0)
				cmd_echo(input);
		else if (ft_strcmp(input[0], "dispenv") == 0)
				ft_print_array(*envcpy);
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
		ft_printf("Direct path ! :D");
}

int		main(int argc, char **argv, char **environ)
{
		(void)argc;
		(void)argv;
		(void)environ;
		char *line;
		char **input;
		char **envcpy;
		char **path;
		char **tmp_path;
		char cwd[1024];
		t_data data;



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
						//if (ft_strchr(input[1], '/') != NULL)
						//		direct_path(input, &envcpy);
						tmp_path = ft_tabdup(path);
						tmp_path = add_bin_to_tab(tmp_path, input[0], data.nb_bin);
						if (ft_strcmp(line, "exit") == 0)
								exit(EXIT_SUCCESS);
						what_cmd(input, &envcpy, data.nb_bin, tmp_path);
				}
				ft_printf("{:blue}[{:lred}MiniShell{:blue}] {:lgreen}➜{:reset} ");
		}
		return (0);
}

// TODO : ls apres un unsetenv donne un command not found donc parser
