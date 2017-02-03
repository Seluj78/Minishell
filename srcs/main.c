/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:13:14 by jlasne            #+#    #+#             */
/*   Updated: 2017/02/03 16:44:16 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		main(int argc, char **argv, char **environ)
{
	/*(void)argc;
	(void)environ;
	(void)argv;
	char **prompt = NULL;
	int i;
	i = 0;
	while (42)
	{
		ft_putstr("mon_prompt>");
		if (get_next_line(0, prompt) > 0)
			ft_printf("%s", prompt[i]);
		i++;
	}
	return (0);*/
	char	*line;

	(void)environ;
	(void)argc;
	(void)argv;
	ft_printf("$> ");
	while (get_next_line(0, &line))
	{
		ft_printf("$> ");
	}
	return (0);
}
