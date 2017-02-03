/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:54:12 by estephan          #+#    #+#             */
/*   Updated: 2017/01/03 19:27:22 by estephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	convert_s(t_data *data)
{
	char	*str;
	int		s;
	char	x;

	x = ' ';
	str = check_precision_max(data, va_arg(*data->ap, char *));
	if (!str)
		str = "(null)";
	s = check_width_nb(data, 1);
	s = (s - ft_strlen(str));
	if (data->c == '0')
		x = '0';
	if (data->moinsloc == TRUE)
	{
		data->ret += ft_putstr(str);
		while (s-- > 0)
			data->ret += write(1, &x, 1);
	}
	else
	{
		while (s-- > 0)
			data->ret += write(1, &x, 1);
		data->ret += ft_putstr(str);
	}
}

void	convert_ls(t_data *data)
{
	int		*str;
	int		s;
	char	x;

	x = ' ';
	str = va_arg(*data->ap, int *);
	if (!str)
		str = L"(null)";
	s = check_width_nb(data, 1);
	s = (s - ft_strwlen(str));
	if (data->c == '0')
		x = '0';
	if (data->moinsloc == TRUE)
	{
		data->ret += ft_putnwstr(str, ft_strwlen(str));
		while (s-- > 0)
			data->ret += write(1, &x, 1);
	}
	else
	{
		while (s-- > 0)
			data->ret += write(1, &x, 1);
		data->nb_len = ft_strwlen(str);
		data->ret += ft_putnwstr(str, data->nb_len);
	}
}
