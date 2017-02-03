/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_jzlh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:28:39 by estephan          #+#    #+#             */
/*   Updated: 2016/12/13 15:58:33 by estephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	converter_j(t_data *data)
{
	if ((data->type == 'd' || data->type == 'i') && data->is_j == TRUE)
		convert_jd(data);
	else if ((data->type == 'x' || data->type == 'X') && data->is_j == TRUE)
		convert_jx(data);
	else if (data->type == 'u' && data->is_j == TRUE)
		convert_ju(data);
	else if (data->type == 'o' && data->is_j == TRUE)
		convert_jo(data);
}

void	converter_z(t_data *data)
{
	if ((data->type == 'd' || data->type == 'i') && data->is_z == TRUE)
		convert_zd(data);
	else if ((data->type == 'x' || data->type == 'X') && data->is_z == TRUE)
		convert_zx(data);
	else if (data->type == 'u' && data->is_z == TRUE)
		convert_zu(data);
	else if (data->type == 'o' && data->is_z == TRUE)
		convert_zo(data);
}

void	converter_h(t_data *data)
{
	if (data->is_hh != TRUE)
	{
		if ((data->type == 'd' || data->type == 'i') && data->is_h == TRUE)
			convert_hhd(data);
		else if ((data->type == 'x' || data->type == 'X') && data->is_h == TRUE)
			convert_hhx(data);
		else if (data->type == 'u' && data->is_h == TRUE)
			convert_hhu(data);
		else if (data->type == 'o' && data->is_h == TRUE)
			convert_hho(data);
		else if (data->type == 'U' && data->is_h == TRUE)
			convert_hhu(data);
	}
	else
	{
		if ((data->type == 'd' || data->type == 'i') && data->is_hh == TRUE)
			convert_hhd(data);
		else if ((data->type == 'x' || data->type == 'X')
					&& data->is_hh == TRUE)
			convert_hhx(data);
		else if (data->type == 'u' && data->is_hh == TRUE)
			convert_hhu(data);
		else if (data->type == 'o' && data->is_hh == TRUE)
			convert_hho(data);
	}
}

void	converter_ll(t_data *data)
{
	if ((data->type == 'd' || data->type == 'i') && data->is_ll == TRUE)
		convert_lld(data);
	else if ((data->type == 'x' || data->type == 'X') && data->is_ll == TRUE)
		convert_llx(data);
	else if (data->type == 'u' && data->is_ll == TRUE)
		convert_llu(data);
	else if (data->type == 'o' && data->is_ll == TRUE)
		convert_llo(data);
}

void	converter_l(t_data *data)
{
	if (data->type == 's' && data->is_l == TRUE)
		convert_ls(data);
	else if ((data->type == 'd' || data->type == 'i') && data->is_l == TRUE)
		convert_lld(data);
	else if (data->type == 'c' && data->is_l == TRUE)
		convert_lc(data);
	else if ((data->type == 'x' || data->type == 'X') && data->is_l == TRUE)
		convert_llx(data);
	else if (data->type == 'u' && data->is_l == TRUE)
		convert_llu(data);
	else if (data->type == 'o' && data->is_l == TRUE)
		convert_llo(data);
	else if (data->type == 'O' && data->is_l == TRUE)
	{
		data->is_ll = TRUE;
		convert_llo(data);
	}
	else if (data->type == 'D' && data->is_l == TRUE)
	{
		data->is_ll = TRUE;
		convert_lld(data);
	}
	else if (data->type == 'U' && data->is_l == TRUE)
		convert_llu(data);
}
