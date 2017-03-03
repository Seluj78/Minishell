/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:17:08 by estephan          #+#    #+#             */
/*   Updated: 2016/12/13 14:52:31 by estephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

static void		print_d1(t_data *data, int s, int a, long long int nb)
{
	if (data->plusloc == TRUE)
		data->ret += write(1, "+", 1);
	if (nb < 0)
	{
		data->ret += write(1, "-", 1);
		nb = -nb;
	}
	s = s + a;
	while (s > 0)
	{
		data->ret += write(1, "0", 1);
		s--;
	}
	if (a != -1)
	{
		ft_putnbr_l(nb);
		data->ret += ft_nblen_l(nb);
	}
}

static void		print_d2_2(t_data *data, int s, int a, long long int nb)
{
	while (s > 0)
	{
		data->ret += write(1, " ", 1);
		s--;
	}
	if (data->plusloc == TRUE)
		data->ret += write(1, "+", 1);
	if (nb < 0)
	{
		data->ret += write(1, "-", 1);
		nb = -nb;
	}
	while (a > 0)
	{
		data->ret += write(1, "0", 1);
		a--;
	}
	if (a != -1)
	{
		ft_putnbr_l(nb);
		data->ret += ft_nblen_l(nb);
	}
}

static void		print_d2(t_data *data, int s, int a, long long int nb)
{
	if (data->moinsloc == TRUE)
	{
		if (data->plusloc == TRUE)
			data->ret += write(1, "+", 1);
		if (nb < 0)
		{
			data->ret += write(1, "-", 1);
			nb = -nb;
		}
		while (a > 0)
		{
			data->ret += write(1, "0", 1);
			a--;
		}
		if (a != -1)
		{
			ft_putnbr_l(nb);
			data->ret += ft_nblen_l(nb);
		}
		while (s-- > 0)
			data->ret += write(1, " ", 1);
	}
	else
		print_d2_2(data, s, a, nb);
}

void			print_d(t_data *data, int s, int a, int nb)
{
	if (data->plusloc == TRUE)
		s--;
	s = (s - a - ft_nblen_l(nb));
	if (a == 0 && nb == 0 && data->is_prec == TRUE)
	{
		a = -1;
		s++;
	}
	if (data->is_prec == TRUE)
		data->c = ' ';
	if (data->c == '0')
		print_d1(data, s, a, nb);
	else
		print_d2(data, s, a, nb);
}
