/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_tab_sep_helper.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 12:17:46 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/09 14:31:40 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			*ft_strepur(char *str, int a)
{
	int		b;
	char	*cpy;
	int		ok;

	b = 0;
	ok = 0;
	cpy = malloc(ft_strlen(str));
	while (str[a] != '\0')
	{
		if (str[a] != ' ' && str[a] != '\t')
		{
			cpy[b++] = str[a];
			ok = 1;
		}
		else if (ok == 1)
		{
			cpy[b++] = ' ';
			ok = 0;
		}
		++a;
	}
	cpy[b] = '\0';
	if (cpy[ft_strlen(cpy) - 1] == ' ' || cpy[ft_strlen(cpy) - 1] == '\t')
		cpy[ft_strlen(cpy) - 1] = '\0';
	return (cpy);
}

void			ft_str_to_tab_sep_helper(char *temp, char ***tab, char sep)
{
	*tab = NULL;
	*tab = ft_alloc_mem(temp, *tab, sep);
}
