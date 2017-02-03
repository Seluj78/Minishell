/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:41:32 by estephan          #+#    #+#             */
/*   Updated: 2016/12/19 18:51:42 by estephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	convert_c(t_data *data)
{
	int		c;
	int		s;
	char	x;

	x = ' ';
	c = va_arg(*data->ap, int);
	s = check_width_nb(data, 1);
	s = (s - 1);
	if (data->c == '0')
		x = '0';
	if (data->moinsloc == TRUE)
	{
		data->ret += write(1, &c, 1);
		while (s-- > 0)
			data->ret += write(1, &x, 1);
	}
	else
	{
		while (s-- > 0)
			data->ret += write(1, &x, 1);
		data->ret += write(1, &c, 1);
	}
}

void	convert_lc(t_data *data)
{
	unsigned int c;

	c = va_arg(*data->ap, unsigned int);
	data->nb_len = ft_charwlen(c);
	data->ret += ft_putwchar(c);
}
