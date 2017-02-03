/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:08:31 by jlasne            #+#    #+#             */
/*   Updated: 2016/11/28 11:09:50 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nblen_base_ll(unsigned long long int n, int base)
{
	int		len;

	len = 1;
	while (n >= (unsigned long long int)base)
	{
		n /= base;
		len++;
	}
	return (len);
}

char		*ft_itoa_base_ll(unsigned long long int n, int base)
{
	int				len;
	char			*str;
	static char		tab[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
	'9', 'A', 'B', 'C', 'D', 'E', 'F'};

	if (base > 16 || base <= 1)
		return (NULL);
	len = ft_nblen_base_ll(n, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (len)
	{
		str[--len] = tab[n % base];
		n = n / base;
	}
	return (str);
}
