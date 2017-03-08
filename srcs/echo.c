/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 10:47:12 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/06 11:08:08 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/minishell.h"

void	cmd_echo(char **input)
{
	int i;
	int size;

	size = ft_arraylen(input);
	i = 1;
	if (size == 1)
	{
		ft_putchar('\n');
		return ;
	}
	while (i < size)
	{
		ft_printf("%s", input[i]);
		if (i < (size - 1))
			ft_putchar(' ');
		else
			ft_putchar('\n');
		i++;
	}
}
