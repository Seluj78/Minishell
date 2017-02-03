/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:04:35 by jlasne            #+#    #+#             */
/*   Updated: 2016/11/03 14:12:07 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, char *s2)
{
	int		cpt;
	int		cpt2;
	int		size;

	cpt = -1;
	cpt2 = 0;
	size = ft_strlen(s2);
	if (!size || !s1)
		return ((char *)s1);
	size--;
	while (s1[++cpt])
	{
		while (s2[cpt2] == s1[cpt + cpt2])
		{
			if (cpt2 == size)
				return ((char *)&s1[cpt]);
			cpt2++;
		}
		cpt2 = 0;
	}
	return (NULL);
}
