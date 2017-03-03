/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 10:45:49 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/03 12:33:44 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **environ)
{
	(void)argc;
	(void)argv;
	(void)environ;
	char *line;
	char **cmd;

	ft_printf("{:blue}[{:lred}MiniShell{:blue}] {:lgreen}➜{:reset} ");
	while (get_next_line(0, &line))
	{
		cmd = ft_str_to_tab_sep(line, ' ', 0);
		if (ft_strcmp(line, "exit") == 0)
			exit(EXIT_SUCCESS);
		//what_cmd(cmd);
		ft_printf("{:blue}[{:lred}MiniShell{:blue}] {:lgreen}➜{:reset} ");
	}
	return (0);
}
