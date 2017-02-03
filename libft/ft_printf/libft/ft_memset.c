/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <jlasne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 21:47:27 by jlasne            #+#    #+#             */
/*   Updated: 2016/11/03 15:54:04 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *ret;

	ret = (unsigned char *)s;
	if (n == 0)
		return (s);
	while (n > 0)
	{
		n--;
		ret[n] = (unsigned char)c;
	}
	s = (void *)ret;
	return (s);
}
