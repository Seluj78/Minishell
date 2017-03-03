/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:37:25 by jlasne            #+#    #+#             */
/*   Updated: 2016/11/03 16:40:37 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strsplit_len(char const *s, char c)
{
	int		t_len;
	int		i;

	i = 0;
	t_len = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			t_len++;
		while (s[i] != c && s[i])
			i++;
	}
	return (t_len);
}

static int		ft_strsplit_word_len(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (!i)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**t_str;
	int		index;
	int		i;

	index = 0;
	i = 0;
	if (!s)
		return (NULL);
	t_str = (char **)malloc(sizeof(char *) * (ft_strsplit_len(s, c) + 1));
	if (!t_str)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			t_str[index] = ft_strsub(&s[i], 0, ft_strsplit_word_len(&s[i], c));
			i = i + ft_strsplit_word_len(&s[i], c);
			index++;
		}
	}
	t_str[index] = NULL;
	return (t_str);
}
