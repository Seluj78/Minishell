/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:20:26 by jlasne            #+#    #+#             */
/*   Updated: 2017/01/03 11:14:57 by estephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int		put_color9(t_data *data, int i)
{
	if (!ft_strncmp(&data->format[data->index], "{:rwhite}", i))
	{
		ft_putstr(RWHITE);
		return (9);
	}
	else if (!ft_strncmp(&data->format[data->index], "{:lblack}", i))
	{
		ft_putstr(LBLACK);
		return (9);
	}
	else if (!ft_strncmp(&data->format[data->index], "{:lred}", i))
	{
		ft_putstr(LRED);
		return (7);
	}
	else if (!ft_strncmp(&data->format[data->index], "{:lgreen}", i))
	{
		ft_putstr(LGREEN);
		return (9);
	}
	else
		return (put_color10(data, i));
}

int		put_color10(t_data *data, int i)
{
	if (!ft_strncmp(&data->format[data->index], "{:lyellow}", i))
	{
		ft_putstr(LYELLOW);
		return (10);
	}
	else if (!ft_strncmp(&data->format[data->index], "{:lblue}", i))
	{
		ft_putstr(LBLUE);
		return (8);
	}
	else if (!ft_strncmp(&data->format[data->index], "{:lpurple}", i))
	{
		ft_putstr(LPURPLE);
		return (10);
	}
	else if (!ft_strncmp(&data->format[data->index], "{:lcyan}", i))
	{
		ft_putstr(LCYAN);
		return (8);
	}
	else
		return (put_color11(data, i));
}

int		put_color11(t_data *data, int i)
{
	if (!ft_strncmp(&data->format[data->index], "{:lwhite}", i))
	{
		ft_putstr(LWHITE);
		return (9);
	}
	else if (!ft_strncmp(&data->format[data->index], "{:fblack}", i))
	{
		ft_putstr(FBLACK);
		return (9);
	}
	else if (!ft_strncmp(&data->format[data->index], "{:fred}", i))
	{
		ft_putstr(FRED);
		return (7);
	}
	else if (!ft_strncmp(&data->format[data->index], "{:fgreen}", i))
	{
		ft_putstr(FGREEN);
		return (9);
	}
	else
		return (put_color12(data, i));
}

int		put_color12(t_data *data, int i)
{
	if (!ft_strncmp(&data->format[data->index], "{:fyellow}", i))
	{
		ft_putstr(FYELLOW);
		return (10);
	}
	else if (!ft_strncmp(&data->format[data->index], "{:fblue}", i))
	{
		ft_putstr(FBLUE);
		return (8);
	}
	else if (!ft_strncmp(&data->format[data->index], "{:fpurple}", i))
	{
		ft_putstr(FPURPLE);
		return (10);
	}
	else if (!ft_strncmp(&data->format[data->index], "{:fcyan}", i))
	{
		ft_putstr(FCYAN);
		return (8);
	}
	else
		return (put_color13(data, i));
}

int		put_color13(t_data *data, int i)
{
	if (!ft_strncmp(&data->format[data->index], "{:fwhite}", i))
	{
		ft_putstr(FWHITE);
		return (9);
	}
	return (0);
}
