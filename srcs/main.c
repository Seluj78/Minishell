/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 10:45:49 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/06 10:13:12 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		test_access(char **path, int size)
{
	int retval;
	int i;

	i = 0;
	retval = -1;
	/*
	 *retval = -1 = command not found
	 */
	while (i < size)
	{
		if (access(path[i], F_OK) == 0)
			retval = i;
		i++;
	}
	return (retval);
}

void	what_cmd(char **input, char **envcpy, int size, char **tmp_path)
{
	int ok;

	ok = 0;
	if (ft_strcmp(input[0], "cd") == 0)
		ft_printf("Command to be built : cd\n");
	else if (ft_strcmp(input[0], "env") == 0)
		ft_printf("Command to be built : env\n");
	else if (ft_strcmp(input[0], "setenv") == 0)
		ft_printf("Command to be built : setenv\n");
	else if (ft_strcmp(input[0], "unsetenv") == 0)
		ft_printf("Command to be built : unsetenv\n");
	else if (ft_strcmp(input[0], "echo") == 0)
		ft_printf("Command to be built : echo\n");
	else if (ft_strcmp(input[0], "dispenv") == 0)
		ft_print_array(envcpy);
	else if (ft_strcmp(input[0], "help") == 0)
		ft_printf("Help section will soonly be displayed here\n");
	//OPTI : tableau de Pointeur sur fonctions
	else
	{
		ok = test_access(tmp_path, size);
		if (ok == -1)
			ft_printf("Minishell: Command not found: %s\n", input[0]);
		else
			ft_printf("Execution de %s\n", tmp_path[ok]);
	}
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
	t_data data;

	envcpy = ft_tabdup(environ);
	path = path_parser(envcpy, &data);
	ft_printf("{:blue}[{:lred}Minishell{:blue}] {:lgreen}➜{:reset} ");
	while (get_next_line(0, &line))
	{
		if (ft_strcmp(line, "\n") > 0)
		{
			input = ft_str_to_tab_sep(line, ' ', 0);
			tmp_path = ft_tabdup(path);
			tmp_path = add_bin_to_tab(tmp_path, input[0], data.nb_bin);
			if (ft_strcmp(line, "exit") == 0)
				exit(EXIT_SUCCESS);
			what_cmd(input, envcpy, data.nb_bin, tmp_path);
		}
		ft_printf("{:blue}[{:lred}MiniShell{:blue}] {:lgreen}➜{:reset} ");
	}
	return (0);
}




/*


   if (environ[0] == NULL) il faudra executer ca :

   int		ft_default_env(t_config *config)
   {
   t_passwd	*passwd;

   ft_free_config(config);
   if (!(config->env = (char **)ft_memalloc(sizeof(char*))))
   return (false);
   ft_setenv("PATH", DPATH, config);
   if ((passwd = getpwuid(getuid())))
   {
   ft_setenv("USER", passwd->pw_name, config);
   ft_setenv("HOME", passwd->pw_dir, config);
   }
   ft_setenv("SHLVL", "1", config);
   return (true);
   }





*/
