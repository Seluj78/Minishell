/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:22:14 by estephan          #+#    #+#             */
/*   Updated: 2016/12/15 16:59:01 by estephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

static void		str_itoa_free(t_data *data, long long int nb)
{
	char	*str;

	if (data->is_ll == TRUE)
		str = (ft_strlower(ft_itoa_base_ll(nb, 16)));
	else if (data->is_l == TRUE)
		str = (ft_strlower(ft_itoa_base_l(nb, 16)));
	else
		str = (ft_strlower(ft_itoa_base(nb, 16)));
	data->ret += ft_putstr(str);
	free(str);
}

static void		print_x1(t_data *data, int s, int a, long long int nb)
{
	if (data->has_hashtag == TRUE)
		data->ret += write(1, "0x", 2);
	s = s + a;
	while (s-- > 0)
		data->ret += write(1, "0", 1);
	if (a != -1)
		str_itoa_free(data, nb);
}

static void		print_x2_2(t_data *data, int s, int a, long long int nb)
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
		data->ret += write(1, "0x", 2);
	if (a != -1)
		str_itoa_free(data, nb);
}

static void		print_x2(t_data *data, int s, int a, long long int nb)
{
	if (data->moinsloc == TRUE)
	{
		while (a > 0)
		{
			data->ret += write(1, "0", 1);
			a--;
		}
		if (data->has_hashtag == TRUE)
			data->ret += write(1, "0x", 2);
		if (a != -1)
			str_itoa_free(data, nb);
		while (s-- > 0)
			data->ret += write(1, " ", 1);
	}
	else
		print_x2_2(data, s, a, nb);
}

void			print_x(t_data *data, int s, int a, long long int nb)
{
	char	*str;

	str = ft_itoa_base(nb, 16);
	if (data->has_hashtag == TRUE)
		s = (s - 2 - a - (ft_strlen(str)));
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
		print_x1(data, s, a, nb);
	else
		print_x2(data, s, a, nb);
}
