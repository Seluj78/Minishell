/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:07:23 by jlasne            #+#    #+#             */
/*   Updated: 2016/11/28 11:07:25 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strlen_nb(char *str)
{
	int		i;

	i = -1;
	while (ft_isdigit(str[++i]))
		;
	return (i);
}

int				ft_atoi(const char *str)
{
	int	neg;
	int	cpt;
	int	n;

	n = 0;
	neg = 0;
	cpt = 0;
	while (str[cpt] == ' ' || str[cpt] == '\t' || str[cpt] == '\r' ||
		str[cpt] == '\n' || str[cpt] == '\v' || str[cpt] == '\f')
		cpt++;
	if (str[cpt] == '-')
		neg = 1;
	if (str[cpt] == '+' || str[cpt] == '-')
		cpt++;
	while (str[cpt] >= '0' && str[cpt] <= '9')
	{
		n = n * 10;
		n = n + (str[cpt] - 48);
		cpt++;
	}
	return (neg == 0 ? n : -n);
}

double			ft_atoid(char *str)
{
	double	result;
	int		i;
	char	*a;

	i = -1;
	a = NULL;
	result = 0;
	while (str[++i] != '.')
	{
		if (str[i] == '\0')
			return (ft_atoi(str));
	}
	a = &str[i + 1];
	i = -1;
	if (!ft_strisdigit(&a[++i]))
		ft_atoi(str);
	result = ft_atoi(str);
	if (result < 0)
		result -= (double)ft_atoi(a) / (double)ft_power(10, ft_strlen_nb(a));
	else
		result += (double)ft_atoi(a) / (double)ft_power(10, ft_strlen_nb(a));
	return (result);
}
