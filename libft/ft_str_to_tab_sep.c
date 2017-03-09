/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_wordtab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 11:17:49 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/09 14:37:43 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char		*ft_strepur2(char *str, int a, int separator)
{
	int		b;
	char	*cpy;
	int		ok;

	b = 0;
	ok = 0;
	cpy = malloc(ft_strlen(str));
	while (str[a] != '\0')
	{
		(ok == 0 && (str[a] == ' ' || str[a] == '\t')) ? ++a : 0;
		if (str[a] != separator)
		{
			cpy[b++] = str[a];
			ok = 1;
		}
		else if (ok == 1)
		{
			cpy[b++] = separator;
			ok = 0;
		}
		++a;
	}
	cpy[b] = '\0';
	(cpy[ft_strlen(cpy) - 1] == separator) ? cpy[ft_strlen(cpy) - 1] = '\0' : 0;
	return (cpy);
}

static char		*ft_do_epur(char *str, int separator, int opt)
{
	str = ft_strepur(str, 0);
	if (opt == 1)
		str = ft_strepur2(str, 0, separator);
	return (str);
}

static int		ft_wordsnbr(char *str, char separator)
{
	int	words;
	int	no;
	int	d;

	d = 0;
	words = 0;
	no = 0;
	while (str[d] != '\0')
	{
		if (str[d] != separator)
		{
			if (no == 0)
			{
				words = words + 1;
				no = 1;
			}
		}
		else
			no = 0;
		++d;
	}
	return (words);
}

char			**ft_alloc_mem(char *str, char **tab, char separator)
{
	int	x;
	int	w;

	x = 0;
	w = ft_wordsnbr(str, separator);
	tab = malloc((w + 1) * sizeof(*tab));
	if (tab == NULL)
		ft_printf("Character error\n");
	while (x < w)
	{
		tab[x] = malloc(ft_strlen(str));
		++x;
	}
	tab[x] = NULL;
	return (tab);
}

char			**ft_str_to_tab_sep(char *str, char separator, int opt)
{
	char	**tab;
	char	*temp;
	int		i;
	int		k;
	int		j;

	j = 0;
	i = 0;
	temp = ft_do_epur(str, separator, opt);
	ft_str_to_tab_sep_helper(temp, &tab, separator);
	while (temp[i] != '\0')
	{
		k = 0;
		(temp[i] == separator) ? ++i : 0;
		while (temp[i] != separator && temp[i] != '\0')
		{
			tab[j][k] = temp[i];
			k++;
			i++;
		}
		tab[j][k] = '\0';
		++j;
	}
	free(temp);
	return (tab);
}
