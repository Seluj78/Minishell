/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 13:03:27 by jlasne            #+#    #+#             */
/*   Updated: 2016/12/15 12:54:10 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	transfer_to_struct(t_data *data, const char *format)
{
	int i;

	i = 0;
	if (!(data->format = (char *)malloc(sizeof(char) * (data->l_format + 1))))
		return ;
	while (format[i] != '\0')
	{
		data->format[i] = format[i];
		i++;
	}
	data->format[i] = '\0';
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str	[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] -= 32;
			i++;
		}
		else
			i++;
	}
	return (str);
}

char	*ft_strlower(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'A' && str[i] <= 'Z'))
		{
			str[i] += 32;
			i++;
		}
		else
			i++;
	}
	return (str);
}

void	ft_putwstr(wchar_t *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	parse_utils(t_data *data, int end)
{
	if (data->conv[end - 1] == 'l')
		data->is_l = TRUE;
	if (data->conv[end - 1] == 'h')
		data->is_h = TRUE;
}
