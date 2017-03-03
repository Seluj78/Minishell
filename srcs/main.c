/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 10:45:49 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/03 13:50:15 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	what_cmd(char **input)
{
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
	else
		ft_printf("Minishell: Command not found: %s\n", input[0]);
}

int		main(int argc, char **argv, char **environ)
{
	(void)argc;
	(void)argv;
	(void)environ;
	char *line;
	char **input;

	ft_printf("{:blue}[{:lred}MiniShell{:blue}] {:lgreen}➜{:reset} ");
	while (get_next_line(0, &line))
	{
		if (ft_strcmp(line, "\n") > 0)
		{
			input = ft_str_to_tab_sep(line, ' ', 0);
			if (ft_strcmp(line, "exit") == 0)
				exit(EXIT_SUCCESS);
			what_cmd(input);
			ft_free_array(input);
		}
		ft_printf("{:blue}[{:lred}MiniShell{:blue}] {:lgreen}➜{:reset} ");
	}
	return (0);
}
