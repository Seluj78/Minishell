/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 11:33:29 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/03 11:53:39 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	**ft_tabdup(char **tab)
{
	int		i;
	int		j;
	char	**dup;

	j = 0;
	i = 0;
	while (tab[i] != '\0')
		i++;
	dup = malloc(i * sizeof(char *));
	while (j < i)
	{
		dup[j] = ft_strdup(tab[j]);
		j++;
	}
	return (dup);
}
