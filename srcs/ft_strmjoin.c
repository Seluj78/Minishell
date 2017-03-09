/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:40:45 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/09 14:03:16 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdarg.h>

int				ft_mfree(unsigned int size, ...)
{
	va_list		ap;
	void		*ptr;

	if (!size)
		return (0);
	va_start(ap, size);
	while (size--)
	{
		ptr = va_arg(ap, void*);
		if (ptr)
			free(ptr);
	}
	va_end(ap);
	return (1);
}

static size_t	ft_strmjoin_count(char **tab, size_t **sizes, size_t n)
{
	size_t		len;

	len = 0;
	if (!(*sizes = malloc(sizeof(size_t) * n)))
		return (0);
	while (n--)
	{
		(*sizes)[n] = (tab[n]) ? ft_strlen(tab[n]) : 0;
		len += (*sizes)[n];
	}
	return (len);
}

static char		*ft_strmjoin_buff(char **tab, size_t *sizes, size_t total_size)
{
	size_t	p;
	char	*buff;
	char	*dest;

	if ((!sizes) && (ft_mfree(1, tab)))
		return (NULL);
	if ((!total_size) && (ft_mfree(2, tab, sizes)))
		return (NULL);
	if ((!(buff = malloc(sizeof(char) * (total_size + 1)))) &&
			(ft_mfree(2, tab, sizes)))
		return (NULL);
	dest = buff;
	p = 0;
	while (tab[p])
	{
		ft_memcpy(dest, tab[p], sizes[p]);
		dest += sizes[p];
		p++;
	}
	*dest = '\0';
	ft_mfree(2, sizes, tab);
	return (buff);
}

char			*ft_strmjoin(const size_t n, ...)
{
	va_list		ap;
	size_t		p;
	size_t		lens;
	char		**tab;
	size_t		*sizes;

	if (!(tab = malloc(sizeof(char*) * (n + 1))))
		return (0);
	va_start(ap, n);
	p = 0;
	while (p < n)
		tab[p++] = va_arg(ap, char *);
	va_end(ap);
	tab[p] = NULL;
	sizes = NULL;
	lens = ft_strmjoin_count(tab, &sizes, n);
	return (ft_strmjoin_buff(tab, sizes, lens));
}
