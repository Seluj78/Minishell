/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 11:09:40 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/10 13:32:12 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	what_cmd_helper(char **tmp_path, int size, char **input, char ***envcpy)
{
	int ok;

	ok = 0;
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

void	what_cmd(char **input, char ***envcpy, int size, char **tmp_path)
{
	ft_printf("lol");
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
		what_cmd_helper(tmp_path, size, input, envcpy);
}
