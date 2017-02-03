/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:28:34 by jlasne            #+#    #+#             */
/*   Updated: 2016/12/19 12:12:56 by estephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

static void	parse_type2(t_data *data, int end)
{
	if (data->conv[end - 1] == 'j')
		data->is_j = TRUE;
	else if (data->conv[end - 1] == 'z')
		data->is_z = TRUE;
}

void		parse_type(t_data *data)
{
	int end;

	end = ft_strlen(data->conv) - 1;
	if (end != 0)
		data->type = data->conv[end];
	if (data->type != 'O' && data->type != 'C' && data->type != 'S'
			&& data->type != 'D' && data->type != 'U' && data->type != 'p')
	{
		if (data->conv[end - 1] == 'h' || data->conv[end - 1] == 'l')
		{
			if (data->conv[end - 2] == 'h' || data->conv[end - 2] == 'l')
			{
				if (data->conv[end - 2] == 'l')
					data->is_ll = TRUE;
				if (data->conv[end - 2] == 'h')
					data->is_hh = TRUE;
			}
			else
				parse_utils(data, end);
		}
		else
			parse_type2(data, end);
	}
}

void		parse_format(t_data *data)
{
	get_type(data);
	parse_type(data);
	if (data->is_l == TRUE)
		converter_l(data);
	else if (data->is_ll == TRUE)
		converter_ll(data);
	else if (data->is_h == TRUE || data->is_hh == TRUE)
		converter_h(data);
	else if (data->is_j == TRUE)
		converter_j(data);
	else if (data->is_z == TRUE)
		converter_z(data);
	else
		converter(data);
	reset_var(data);
}

static void	converter2(t_data *data)
{
	if (data->type == 'O')
		convert_llo(data);
	else if (data->type == 'C')
		convert_lc(data);
	else if (data->type == 'S')
		convert_ls(data);
	else if (data->type == 'D')
		convert_lld(data);
	else if (data->type == 'U')
		convert_llu(data);
	else if (data->type == 37)
		convert_percent(data);
	else if (data->type == 'r')
		convert_r(data);
	else
		return ;
}

void		converter(t_data *data)
{
	if (data->type == 's')
		convert_s(data);
	else if (data->type == 'd' || data->type == 'i')
		convert_d(data);
	else if (data->type == 'c')
		convert_c(data);
	else if (data->type == 'p')
		convert_p(data);
	else if (data->type == 'x' || data->type == 'X')
		convert_x(data);
	else if (data->type == 'u')
		convert_u(data);
	else if (data->type == 'o')
		convert_o(data);
	else
		converter2(data);
}
