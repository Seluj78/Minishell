/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 12:57:41 by jlasne            #+#    #+#             */
/*   Updated: 2017/02/04 13:14:28 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	str_is_in(char *str, char *to_find)
{
	int	save;
	int	i;
	int	a;

	a = 0;
	i = 0;
	save = 0;
	while (str[i] != '\0')
	{
		save = i;
		while ((str[i] == to_find[a]) && ((str[i] != '\0')
					|| (to_find[a] != '\0')))
		{
			i = i + 1;
			a = a + 1;
		}
		if (to_find[a] == '\0')
			return (1);
		a = 0;
		i = i + 1;
	}
	return (0);
}

static char	*path_dup(char *str, int i, int j)
{
	char	*dup;
	int	k;

	k = 0;
	dup = malloc((j - i + 1) * sizeof(*dup));
	if (dup == NULL)
		ft_printf("Error character\n");
	while (str[i] != '\0')
	{
		dup[k] = str[i];
		++i;
		++k;
	}
	dup[k] = '\0';
	return (dup);
}

static char	*get_env(char **env, char *data)
{
	int   i;
	char  *path;

	i = 0;
	while (env[i] != NULL)
	{
		if (str_is_in(env[i], data) != 0)
		{
			path = path_dup(env[i], ft_strlen(data), ft_strlen(env[i]));
			return (path);
		}
		++i;
	}
	return (NULL);
}

static char	**do_absolute(void)
{
	char	**tab;

	tab = malloc(17 * sizeof(*tab));
	if (tab == NULL)
		ft_printf("Error character\n");
	tab[0] = ft_strdup("/usr/site/sbin");
	tab[1] = ft_strdup("/usr/site/bin");
	tab[2] = ft_strdup("/usr/netsoul/sbin");
	tab[3] = ft_strdup("/usr/netsoul/bin");
	tab[4] = ft_strdup("/usr/heimdal/sbin");
	tab[5] = ft_strdup("/usr/heimdal/bin");
	tab[6] = ft_strdup("/usr/arla/sbin");
	tab[7] = ft_strdup("/usr/arla/bin");
	tab[8] = ft_strdup("/usr/local/sbin");
	tab[9] = ft_strdup("/usr/local/bin");
	tab[10] = ft_strdup("/usr/sbin");
	tab[11] = ft_strdup("/usr/bin");
	tab[12] = ft_strdup("/sbin");
	tab[13] = ft_strdup("/bin");
	tab[14] = ft_strdup("/usr/sfw/bin");
	tab[15] = ft_strdup("/usr/ccs/bin");
	tab[16] = NULL;
	return (tab);
}

char	**path_parser(char **env)
{
	char	**tab;
	char	*path = NULL;

	tab = NULL;
	if (env == NULL)
		tab = do_absolute();
	else
	{
		path = get_env(env, "PATH=");
		if (path == NULL)
			tab = do_absolute();
		else
			tab = str_to_tab_sep(path, ':', 0);
	}
	//ft_printf("%s", path);
	free(path);
	return (tab);
}
