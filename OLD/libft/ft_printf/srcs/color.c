/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:25:24 by jlasne            #+#    #+#             */
/*   Updated: 2016/12/15 12:28:32 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int		put_color(t_data *data, int i)
{
	if (!ft_strncmp(&data->format[data->index], "{:reset}", i))
	{
		ft_putstr(RESET);
		return (8);
	}
	else if (!ft_strncmp(&data->format[data->index], "{:black}", i))
	{
		ft_putstr(BLACK);
		return (8);
	}
	else if (!ft_strncmp(&data->format[data->index], "{:red}", i))
	{
		ft_putstr(RED);
		return (6);
	}
	else if (!ft_strncmp(&data->format[data->index], "{:green}", i))
	{
		ft_putstr(GREEN);
		return (8);
	}
	else
		return (put_color2(data, i));
}

int		put_color2(t_data *data, int i)
{
	if (!ft_strncmp(&data->format[data->index], "{:yellow}", i))
	{
		ft_putstr(YELLOW);
		return (9);
	}
	else if (!ft_strncmp(&data->format[data->index], "{:blue}", i))
	{
		ft_putstr(BLUE);
		return (7);
	}
	else if (!ft_strncmp(&data->format[data->index], "{:purple}", i))
	{
		ft_putstr(PURPLE);
		return (9);
	}
	else if (!ft_strncmp(&data->format[data->index], "{:cyan}", i))
	{
		ft_putstr(CYAN);
		return (7);
	}
	else
		return (put_color3(data, i));
}

int		put_color3(t_data *data, int i)
{
	if (!ft_strncmp(&data->format[data->index], "{:white}", i))
	{
		ft_putstr(WHITE);
		return (8);
	}
	else if (!ft_strncmp(&data->format[data->index], "{:bblack}", i))
	{
		ft_putstr(BBLACK);
		return (9);
	}
	else if (!ft_strncmp(&data->format[data->index], "{:bred}", i))
	{
		ft_putstr(BRED);
		return (7);
	}
	else if (!ft_strncmp(&data->format[data->index], "{:bgreen}", i))
	{
		ft_putstr(BGREEN);
		return (9);
	}
	else
		return (put_color4(data, i));
}

void	parse_color(t_data *data)
{
	int i;
	int j;

	if (data->format[data->index] == '{'
			&& data->format[data->index + 1] == ':')
	{
		j = data->index;
		i = 0;
		while (data->format[j] != '}')
		{
			i++;
			j++;
		}
		data->index += put_color(data, i);
	}
}
