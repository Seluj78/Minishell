/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:30:56 by estephan          #+#    #+#             */
/*   Updated: 2016/12/15 13:29:51 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

static int		part_2(t_data *data, int s, int i)
{
	while (s == 0 && data->conv[i] && data->conv[i] != '.')
	{
		if (data->conv[i] >= '0' && data->conv[i] <= '9')
		{
			if (data->conv[i] == '0' && data->moinsloc == FALSE)
				data->c = '0';
			else
				s++;
			while (data->conv[i + s] >= '0' && data->conv[i + s] <= '9')
			{
				s++;
			}
		}
		i++;
	}
	return (s);
}

static int		part_3(t_data *data, int s, int i, char *str)
{
	while (s == 0 && data->conv[i] && data->conv[i] != '.')
	{
		if (data->conv[i] >= '1' && data->conv[i] <= '9')
		{
			str[s] = data->conv[i];
			i++;
			s++;
			while (data->conv[i] >= '0' && data->conv[i] <= '9')
			{
				str[s] = data->conv[i];
				i++;
				s++;
			}
		}
		i++;
	}
	str[s] = '\0';
	s = ft_atoi(str);
	return (s);
}

int				check_width_nb(t_data *data, long long int nb)
{
	int		i;
	int		s;
	char	*str;

	i = 0;
	s = 0;
	data->c = ' ';
	check_plus(data);
	if (nb < 0)
		data->plusloc = FALSE;
	check_moins(data);
	s = part_2(data, s, i);
	str = ft_strnew(s);
	i = 0;
	s = 0;
	s = part_3(data, s, i, str);
	free(str);
	return (s);
}
