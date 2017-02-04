/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 11:09:45 by jlasne            #+#    #+#             */
/*   Updated: 2017/02/04 13:07:12 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int		count_word(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 1;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] == ' ' && str[i + 1] != '\0')
			n++;
		i++;
	}
	return (n);
}

static int		countchar(char *str)
{
	int	c;

	c = 0;
	while ((str[c] != ' ') && (str[c] != '\0') && (str[c] != '\n'))
		c++;
	c += 1;
	return (c);
}

char			**str_to_wordtab(char *str)
{
	char	**tab;
	int		i;
	int		b;
	int		a;

	b = 0;
	i = 0;
	a = 0;
	tab = malloc(sizeof(*tab) * ((count_word(str) + 1)));
	while (str[i] != '\t' && str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\n')
		{
			while (str[i] == ' ')
				i++;
			a = a + 1;
			b = 0;
		}
		tab[a] = malloc(sizeof(**tab) * ((countchar(str + i) + 1)));
		while ((str[i] != ' ')  && (str[i] != '\n') && (str[i] != '\0'))
			tab[a][b++] = str[i++];
		tab[a][b] = '\0';
	}
	tab[a + 1] = 0;
	return (tab);
}
