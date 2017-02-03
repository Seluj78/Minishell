/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:02:00 by jlasne            #+#    #+#             */
/*   Updated: 2016/11/03 13:09:07 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	c2;
	int				i;

	i = 0;
	str = (unsigned char *)s;
	c2 = (unsigned char)c;
	while (n--)
	{
		if (str[i] == c2)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
