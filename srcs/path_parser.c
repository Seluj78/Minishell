/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 12:57:41 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/09 14:08:21 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*path_dup(char *str, int i, int j)
{
	char	*dup;
	int		k;

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
	int		i;
	char	*path;

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

int			count_path_size(char *path, char sep)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (path[i] != '\0')
	{
		if (path[i] == sep)
			count++;
		i++;
	}
	return (count + 1);
}

char		**path_parser(char **env, t_data *data)
{
	char	**tab;
	char	*path;

	path = NULL;
	tab = NULL;
	if (env[0] == NULL)
		tab = do_absolute();
	else
	{
		path = get_env(env, "PATH=");
		if (path == NULL)
			tab = do_absolute();
		else
			tab = ft_str_to_tab_sep(path, ':', 0);
	}
	data->nb_bin = count_path_size(path, ':');
	free(path);
	return (tab);
}
