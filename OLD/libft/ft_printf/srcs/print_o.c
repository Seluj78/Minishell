/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:27:25 by estephan          #+#    #+#             */
/*   Updated: 2016/12/15 17:07:56 by estephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

static void		str_itoa_free(t_data *data, long long int nb)
{
	char	*str;

	if (data->is_ll == TRUE)
		str = ft_itoa_base_ll(nb, 8);
	else if (data->is_l == TRUE)
		str = ft_itoa_base_l(nb, 8);
	else
		str = ft_itoa_base(nb, 8);
	data->ret += ft_putstr(str);
	free(str);
}

static void		print_o1(t_data *data, int s, int a, long long int nb)
{
	if (data->has_hashtag == TRUE)
		data->ret += write(1, "0", 1);
	s = s + a;
	while (s > 0)
	{
		data->ret += write(1, "0", 1);
		s--;
	}
	if (a != -1)
		str_itoa_free(data, nb);
}

static void		print_o2_2(t_data *data, int s, int a, long long int nb)
{
	while (s > 0)
	{
		data->ret += write(1, " ", 1);
		s--;
	}
	while (a > 0)
	{
		data->ret += write(1, "0", 1);
		a--;
	}
	if (data->has_hashtag == TRUE)
		data->ret += write(1, "0", 1);
	if (a != -1)
		str_itoa_free(data, nb);
}

static void		print_o2(t_data *data, int s, int a, long long int nb)
{
	if (data->moinsloc == TRUE)
	{
		while (a > 0)
		{
			data->ret += write(1, "0", 1);
			a--;
		}
		if (data->has_hashtag == TRUE)
			data->ret += write(1, "0", 1);
		if (a != -1)
			str_itoa_free(data, nb);
		while (s-- > 0)
			data->ret += write(1, " ", 1);
	}
	else
		print_o2_2(data, s, a, nb);
}

void			print_o(t_data *data, int s, int a, long long int nb)
{
	char	*str;

	str = ft_itoa_base(nb, 8);
	if (data->has_hashtag == TRUE)
		s = (s - 1 - a - (ft_strlen(str)));
	else
		s = (s - a - (ft_strlen(str)));
	free(str);
	if (a == 0 && nb == 0 && data->is_prec == TRUE)
	{
		a = -1;
		s++;
	}
	if (data->is_prec == TRUE)
		data->c = ' ';
	if (data->c == '0')
		print_o1(data, s, a, nb);
	else
		print_o2(data, s, a, nb);
}
