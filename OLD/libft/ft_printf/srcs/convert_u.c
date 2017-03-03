/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:58:58 by estephan          #+#    #+#             */
/*   Updated: 2016/12/19 18:22:08 by estephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	convert_hhu(t_data *data)
{
	unsigned char		c;
	unsigned short int	nb;
	char				*str;

	if (data->is_hh == TRUE)
	{
		c = (unsigned char)va_arg(*data->ap, int);
		str = ft_itoa_base(c, 10);
		data->ret += ft_putstr(str);
	}
	else
	{
		nb = (unsigned short int)va_arg(*data->ap, unsigned int);
		str = ft_itoa_base(nb, 10);
		data->ret += ft_putstr(str);
	}
	free(str);
}

void	convert_u(t_data *data)
{
	unsigned int	nb;
	int				a;
	int				s;

	nb = va_arg(*data->ap, unsigned int);
	a = check_precision(data, (intmax_t)nb);
	s = check_width_nb(data, (intmax_t)nb);
	print_u(data, s, a, nb);
}

void	convert_llu(t_data *data)
{
	unsigned long long int	nb;
	unsigned long int		nb1;
	char					*str;

	if (data->is_ll == TRUE)
	{
		nb = va_arg(*data->ap, unsigned long long int);
		str = ft_itoa_base_ll(nb, 10);
		data->ret += ft_putstr(str);
	}
	else
	{
		nb1 = va_arg(*data->ap, unsigned long int);
		str = ft_itoa_base_l(nb1, 10);
		data->ret += ft_putstr(str);
	}
	free(str);
}

void	convert_zu(t_data *data)
{
	unsigned long long	nb;
	char				*str;

	nb = (unsigned long long)va_arg(*data->ap, int);
	str = ft_itoa_base_ll(nb, 10);
	data->ret += ft_putstr(str);
	free(str);
}

void	convert_ju(t_data *data)
{
	uintmax_t	nb;
	char		*str;

	nb = va_arg(*data->ap, uintmax_t);
	str = ft_itoa_base_uint(nb, 10);
	data->ret += ft_putstr(str);
	free(str);
}
