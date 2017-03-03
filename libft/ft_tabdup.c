/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 11:33:29 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/03 14:10:04 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	**ft_tabdup(char **arr)
{
	int		i;
	int		len;
	char	**cpy;

	i = -1;
	len = ft_arraylen(arr);
	cpy = (char **)malloc(sizeof(char *) * len + 1);
	while (arr && arr[++i])
		cpy[i] = ft_strdup(arr[i]);
	cpy[i] = NULL;
	return (cpy);
}
