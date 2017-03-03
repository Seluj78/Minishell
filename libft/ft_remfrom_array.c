/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remfrom_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 11:50:13 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/03 11:53:10 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		**copy_array_without(int rem, char **new_arr, char **arr, int len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (i != rem)
		{
			new_arr[j] = (char*)malloc(sizeof(char) * (ft_strlen(arr[i]) + 1));
			if (new_arr[j])
			{
				ft_strcpy(new_arr[j], arr[i]);
				j = j + 1;
			}
		}
		i = i + 1;
	}
	new_arr[j] = NULL;
	return (new_arr);
}

char		**ft_remfrom_array(int rem, char **arr)
{
	int		len;
	char	**new_arr;

	new_arr = NULL;
	if (arr != NULL)
	{
		len = ft_arraylen(arr);
		new_arr = (char**)malloc(sizeof(char*) * (len));
		new_arr = copy_array_without(rem, new_arr, arr, len);
		ft_free_array(arr);
	}
	return (new_arr);
}
