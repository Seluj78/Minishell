/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 10:45:49 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/03 11:12:56 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **environ)
{
	(void)argc;
	(void)argv;
	(void)environ;
	char *line;

	ft_printf("{:blue}[{:lred}MiniShell{:blue}] {:lgreen}➜{:reset} ");
	while (get_next_line(0, &line))
	{
		if (ft_strcmp(line, "exit") == 0)
			exit(EXIT_SUCCESS);
		ft_printf("{:blue}[{:lred}MiniShell{:blue}] {:lgreen}➜{:reset} ");
	}
	return (0);
}
