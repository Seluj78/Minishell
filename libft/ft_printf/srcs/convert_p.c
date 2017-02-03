/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:05:54 by estephan          #+#    #+#             */
/*   Updated: 2017/01/02 14:46:23 by estephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

static void		convert_p2(t_data *data, int a, int l, long long n)
{
	char	*str;

	str = ft_itoa_base(n, 16);
	l += 1;
	if (n >= -2147483648 && n <= 2147483647)
		data->ret += ft_putstr("0x");
	else
		data->ret += ft_putstr("0x7fff");
	while (a-- > 0)
		data->ret += write(1, "0", 1);
	while (l-- > 0 && data->c == '0')
		data->ret += write(1, &data->c, 1);
	data->ret += ft_putstr(str);
	l += 1;
	while (l-- > 0 && data->c == ' ')
		data->ret += write(1, &data->c, 1);
	free(str);
}

void			convert_p(t_data *data)
{
	long long	n;
	long long	nb;
	char		*str;
	int			l;
	int			a;

	n = (long long)va_arg(*data->ap, void *);
	str = ft_itoa_base(n, 16);
	l = ft_strlen(str);
	while (l-- > 1)
		nb = (nb * 10);
	a = check_precision(data, (intmax_t)nb);
	l = check_width_nb(data, (intmax_t)nb);
	if (n >= -2147483648 && n <= 2147483647)
		l = (l - a - (ft_strlen(str)) - 2);
	else
		l = (l - a - (ft_strlen(str)) - 6);
	while (l-- > 0 && data->c == ' ' && data->moinsloc == FALSE)
		data->ret += write(1, &data->c, 1);
	convert_p2(data, a, l, n);
	free(str);
}
