/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:05:04 by estephan          #+#    #+#             */
/*   Updated: 2017/01/04 14:30:09 by estephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	convert_d(t_data *data)
{
	long long int	nb1;
	int				a;
	int				s;
	int				nb;

	a = 0;
	nb1 = va_arg(*data->ap, long long int);
	while (nb1 > 2147483647)
		nb1 = (nb1 - 4294967296);
	nb = nb1;
	if (nb > 0)
		check_plus(data);
	a = check_precision(data, (intmax_t)nb);
	s = check_width_nb(data, (intmax_t)nb);
	check_spaces(data);
	if (nb > -1 && data->plusloc == FALSE && data->check_spaces == TRUE)
	{
		data->ret += write(1, " ", 1);
		s--;
	}
	print_d(data, s, a, nb);
}

void	convert_hhd(t_data *data)
{
	signed char	c;
	short int	nb;

	if (data->is_hh == TRUE)
	{
		c = (signed char)va_arg(*data->ap, int);
		ft_putnbr((int)c);
		data->ret += ft_nblen((int)c);
	}
	else
	{
		nb = (short int)va_arg(*data->ap, int);
		if (nb > 0)
			check_plus(data);
		check_precision(data, nb);
		ft_putnbr(nb);
		data->ret += ft_nblen(nb);
	}
}

void	convert_lld(t_data *data)
{
	long long int	nb;
	long int		nb1;

	if (data->is_ll == TRUE)
	{
		nb = va_arg(*data->ap, long long int);
		if (nb > 0)
			check_plus(data);
		ft_putnbr_ll(nb);
		data->ret += ft_nblen_ll(nb);
	}
	else
	{
		nb1 = (long int)va_arg(*data->ap, long long int);
		if (nb1 > 0)
			check_plus(data);
		if (data->plusloc == TRUE)
			data->ret += write(1, "+", 1);
		ft_putnbr_ll(nb1);
		data->ret += ft_nblen_ll(nb1);
	}
}

void	convert_zd(t_data *data)
{
	ssize_t nb;

	nb = va_arg(*data->ap, ssize_t);
	if (nb > 0)
		check_plus(data);
	ft_putnbr_ll(nb);
	data->ret += ft_nblen_ll(nb);
}

void	convert_jd(t_data *data)
{
	long long nb;

	nb = (long long)va_arg(*data->ap, long long int);
	if (nb > 0)
		check_plus(data);
	ft_putnbr_ll(nb);
	data->ret += ft_nblen_ll(nb);
}
