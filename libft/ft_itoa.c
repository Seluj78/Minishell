/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:08:01 by jlasne            #+#    #+#             */
/*   Updated: 2016/11/28 11:08:03 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	nbr;

	nbr = n;
	len = ft_nblen_l(nbr);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (n < 0)
		nbr = -nbr;
	while (len)
	{
		str[--len] = 48 + (nbr % 10);
		nbr = nbr / 10;
	}
	if (str[len] == '0' && str[1] != '\0')
		str[len] = '-';
	return (str);
}

/*
** len-- is in the while because it cause a bug if he is in the parenthese
** he becomes -1 after it
*/
