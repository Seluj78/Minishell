/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:13:14 by jlasne            #+#    #+#             */
/*   Updated: 2017/02/03 16:56:45 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		main(int argc, char **argv, char **environ)
{
	char	*line;

	(void)environ;
	(void)argc;
	(void)argv;
	ft_printf("{:lgreen}$>{:reset} ");
	while (get_next_line(0, &line))
	{
		ft_printf("{:lgreen}$>{:reset} ");
	}




	return (0);
}
