/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_nbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:07:50 by jlasne            #+#    #+#             */
/*   Updated: 2016/11/28 11:09:39 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_base(char c, int base)
{
	int				j;
	static char		tab[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
	'9', 'A', 'B', 'C', 'D', 'E', 'F'};

	if (c >= 'a' && c <= 'f')
		c -= 32;
	j = -1;
	while (++j <= base && c != tab[j])
		;
	if (c == tab[j])
		return (j);
	return (-1);
}

static int		ft_atoi_nloop(const char *str, int base, int len)
{
	int		result;
	int		base_val;
	int		i;

	result = 0;
	i = 0;
	while ((ft_isdigit(str[i]) || (str[i] >= 'A' && str[i] <= 'F') ||
	(str[i] >= 'a' && str[i] <= 'f')) && len--)
	{
		base_val = ft_base(str[i], base);
		if (base_val == -1)
			return (result);
		result *= base;
		result += base_val;
		i++;
	}
	return (result);
}

unsigned int	ft_atoi_nbase(const char *str, int base, int len)
{
	int		i;
	int		n;

	i = 0;
	n = 1;
	if (base > 16)
		return (0);
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\t' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		n = -1;
		i++;
	}
	return (n == -1 ? -ft_atoi_nloop(&str[i], base, len) :
	ft_atoi_nloop(&str[i], base, len));
}
