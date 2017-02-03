/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:09:21 by jlasne            #+#    #+#             */
/*   Updated: 2016/11/28 11:09:24 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strisdigit(char *str)
{
	int		i;
	int		end;

	i = -1;
	end = 0;
	while (str[++i] == ' ')
		;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if ((str[i] >= 48 && str[i] <= 57) && end == 0)
			i++;
		else if (str[i] == ' ' && end == 0)
			end = 1;
		else
			return (0);
	}
	return (1);
}
