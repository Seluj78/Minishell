/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:10:05 by estephan          #+#    #+#             */
/*   Updated: 2017/01/03 19:26:17 by estephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	convert_hho(t_data *data)
{
	unsigned char		nb;
	short unsigned int	nb1;

	if (data->is_hh == TRUE)
	{
		nb = (unsigned char)va_arg(*data->ap, int);
		check_precision(data, nb);
		data->ret += ft_putstr(ft_itoa_base(nb, 8));
	}
	else
	{
		nb1 = (short unsigned int)va_arg(*data->ap, unsigned int);
		check_precision(data, nb1);
		data->ret += ft_putstr(ft_itoa_base(nb1, 8));
	}
}

void	convert_o(t_data *data)
{
	unsigned int	nb;
	int				a;
	int				s;
	unsigned int	nbh;
	char			*str;

	nb = va_arg(*data->ap, unsigned int);
	check_hashtag(data);
	str = ft_itoa_base(nb, 8);
	nbh = ft_atoi(str);
	a = check_precision(data, nbh);
	s = check_width_nb(data, nbh);
	free(str);
	print_o(data, s, a, nb);
}

void	convert_llo(t_data *data)
{
	long long unsigned int		nb;
	long unsigned int			nb1;

	if (data->is_ll == TRUE)
	{
		nb = va_arg(*data->ap, long long unsigned int);
		data->ret += ft_putstr(ft_itoa_base_ll(nb, 8));
	}
	else
	{
		nb1 = va_arg(*data->ap, long unsigned int);
		data->ret += ft_putstr(ft_itoa_base_ll(nb1, 8));
	}
}

void	convert_zo(t_data *data)
{
	ssize_t nb;

	nb = va_arg(*data->ap, ssize_t);
	data->ret += ft_putstr(ft_itoa_base_ll(nb, 8));
}

void	convert_jo(t_data *data)
{
	uintmax_t nb;

	nb = va_arg(*data->ap, uintmax_t);
	data->ret += ft_putstr(ft_itoa_base_ll(nb, 8));
}
