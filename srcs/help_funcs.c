/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:59:45 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/10 11:09:05 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			my_strncmp(char *s1, char *s2, int n)
{
	int		result;
	int		i;

	if (n > 0)
	{
		result = 0;
		i = 0;
		while (i < n
				&& s1[i] != '\0'
				&& s2[i] != '\0'
				&& !result)
		{
			result = s1[i] - s2[i];
			i++;
		}
		if (i < n - 1 && s1[i] == '\0' && s2[i] != '\0')
			return (-100);
		else if (i < n - 1 && s2[i] == '\0' && s1[i] != '\0')
			return (100);
		else
			return (result);
	}
	return (0);
}

void		direct_path(char **input, char ***envcpy)
{
	(void)envcpy;
	(void)input;
	if (access(input[0], F_OK) == 0)
		cmd_exec(input[0], input, *envcpy);
	else
		ft_printf("Minishell: Error: Command not found\n");
}

size_t		ft_tabcount(void **tab)
{
	size_t	p;

	p = 0;
	while (tab[p])
		p++;
	return (p + 1);
}

char		**clear_bintab(char **tab, size_t size)
{
	while (size--)
		if (tab[size])
			free(tab[size]);
	free(tab);
	return (NULL);
}

char		**get_bintab(char **path_tab, size_t size, const char *binstr)
{
	const size_t	fullsize = size;
	char			**tab;

	if (!(tab = malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	tab[size] = NULL;
	while (size--)
	{
		tab[size] = ft_strmjoin(3, path_tab[size], "/", binstr);
		if (!tab[size])
			return (clear_bintab(tab, fullsize));
	}
	return (tab);
}
