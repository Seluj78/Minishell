/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:29:15 by estephan          #+#    #+#             */
/*   Updated: 2016/12/09 15:33:36 by estephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	convert_percent(t_data *data)
{
	int s;

	s = check_width_nb(data, 1);
	s = (s - 1);
	if (data->moinsloc == TRUE)
	{
		data->ret += write(1, "%", 1);
		while (s > 0)
		{
			data->ret += write(1, " ", 1);
			s--;
		}
	}
	else
	{
		while (s > 0)
		{
			data->ret += write(1, " ", 1);
			s--;
		}
		data->ret += write(1, "%", 1);
	}
}
