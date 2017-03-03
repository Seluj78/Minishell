/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:10:36 by estephan          #+#    #+#             */
/*   Updated: 2016/11/30 14:11:18 by estephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_write_mask(char *mask, int bytes)
{
	int		i;
	int		w;

	i = -1;
	while (++i < bytes)
	{
		w = ft_atoi_nbase(&mask[i * 8], 2, 8);
		write(1, &w, 1);
	}
	return (i);
}

static int		ft_wchar_help(int c, char *mask, int bytes)
{
	int		i;

	i = (8 * bytes) - 1;
	while (i && c)
	{
		if (mask[i] != 'x')
			i--;
		else
		{
			mask[i--] = 48 + (c % 2);
			c = c / 2;
		}
	}
	i = -1;
	while (mask[++i])
	{
		if (mask[i] == 'x')
			mask[i] = '0';
	}
	return (ft_write_mask(mask, bytes));
}

int				ft_putnwchar(int c, int size)
{
	int		len;
	char	mask2[16];
	char	mask3[24];
	char	mask4[32];

	if (((len = ft_binlen(c)) >= 0) && size < 0)
		return (0);
	if (len <= 7 && size > 0)
		return (write(1, &c, 1));
	else if (len <= 11 && size > 1)
	{
		ft_strcpy(mask2, "110xxxxx10xxxxxx");
		return (ft_wchar_help(c, mask2, 2));
	}
	else if (len > 11 && len <= 16 && size > 2)
	{
		ft_strcpy(mask3, "1110xxxx10xxxxxx10xxxxxx");
		return (ft_wchar_help(c, mask3, 3));
	}
	else if (size > 3)
	{
		ft_strcpy(mask4, "11110xxx10xxxxxx10xxxxxx10xxxxxx");
		return (ft_wchar_help(c, mask4, 4));
	}
	return (0);
}
