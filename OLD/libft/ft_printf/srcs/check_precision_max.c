/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision_max.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:30:56 by estephan          #+#    #+#             */
/*   Updated: 2017/01/03 19:27:19 by estephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

static char		*check_precision_max2(t_data *data, size_t k, char *str2)
{
	int		s;
	int		i;
	char	*str;

	s = 0;
	str = ft_strnew(k);
	i = 0;
	while (data->conv[i++] != '\0' && s == 0)
	{
		if (data->conv[i] == '.')
		{
			i++;
			while (data->conv[i] >= '0' && data->conv[i] <= '9')
				str[s++] = data->conv[i++];
		}
	}
	str[s] = '\0';
	s = ft_atoi(str);
	free(str);
	str = ft_strnew(s);
	ft_strncpy(str, str2, s);
	return (str);
}

char			*check_precision_max(t_data *data, char *str2)
{
	int		i;
	size_t	k;
	int		r;

	i = 0;
	k = 0;
	r = 0;
	while (data->conv[i++] != '\0' && k == 0)
	{
		if (data->conv[i] == '.')
		{
			r = 1;
			i++;
			while (data->conv[i] >= '0' && data->conv[i] <= '9')
			{
				i++;
				k++;
			}
		}
	}
	if (r == 1)
		str2 = check_precision_max2(data, k, str2);
	return (str2);
}
