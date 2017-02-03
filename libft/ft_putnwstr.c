/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:01:21 by estephan          #+#    #+#             */
/*   Updated: 2016/11/30 14:01:55 by estephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_putnwstr(int *str, int len)
{
	int		ret;
	int		i;

	ret = 0;
	i = -1;
	while (ret < len && str[++i])
		ret += ft_putnwchar(str[i], len - ret);
	return (ret);
}
