/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:30:56 by estephan          #+#    #+#             */
/*   Updated: 2017/01/04 14:37:21 by estephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void		check_hashtag(t_data *data)
{
	int		i;

	i = 0;
	data->has_hashtag = FALSE;
	while (data->conv[i] != '\0' && data->conv[i - 1] != '#')
	{
		if (data->conv[i] == '#')
			data->has_hashtag = TRUE;
		i++;
	}
}

void		check_moins(t_data *data)
{
	int i;

	i = 0;
	data->moinsloc = FALSE;
	while (data->conv[i] != '\0')
	{
		if (data->conv[i] == '-')
			data->moinsloc = TRUE;
		i++;
	}
}

void		check_plus(t_data *data)
{
	int		i;

	i = 0;
	data->plusloc = FALSE;
	while (data->conv[i] != '\0' && data->conv[i - 1] != '+')
	{
		if (data->conv[i] == '+')
			data->plusloc = TRUE;
		i++;
	}
}

static int	check_precision2(t_data *data, size_t k, long long int nb, int i)
{
	char	*str;
	int		s;

	str = ft_strnew(k);
	s = 0;
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
	if (nb < 0)
		s++;
	i = 0;
	while (s-- > ft_nblen_l(nb))
		i++;
	return (i);
}

int			check_precision(t_data *data, long long int nb)
{
	int		i;
	size_t	k;

	i = 0;
	k = 0;
	while (data->conv[i] != '\0' && k == 0)
	{
		if (data->conv[i] == '.')
		{
			data->is_prec = TRUE;
			i++;
			while (data->conv[i] >= '0' && data->conv[i] <= '9')
			{
				i++;
				k++;
			}
		}
		i++;
	}
	i = 0;
	return (check_precision2(data, k, nb, i));
}
