/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 12:57:41 by jlasne            #+#    #+#             */
/*   Updated: 2017/02/08 16:09:48 by jlasne           ###   ########.fr       */
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

int 	count_path_size(char *path, char sep)
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

char		*ft_strjoin_sep(char *s1, char *sep, char *s2)
{
		char	*str;
		int		len;
		int		i;

		i = -1;
		len = ft_strlen((char*)s1) + ft_strlen((char*)s2) + ft_strlen(sep) + 1;
		if (!(str = (char*)malloc(sizeof(char) * len)))
				return (NULL);
		while (*s1)
		{
				str[++i] = *s1;
				s1++;
		}
		while (*sep)
		{
				str[++i] = *sep;
				sep++;
		}
		while (*s2)
		{
				str[++i] = *s2;
				s2++;
		}
		str[++i] = '\0';
		return (str);
}

char **add_bin_to_tab(char **tab, char *bin, int nb_bin)
{
		char	*tmp;
		int i;

		i = 0;
		while (i < nb_bin)
		{
			tmp = ft_strjoin_sep(tab[i], "/", bin);
			tab[i] = ft_strdup(tmp);
			//ft_printf("%s\n", tab[i]);
			free(tmp);
			i++;
		}
		return (tab);
}



char	**path_parser(char **env, t_data *data, char *bin)
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
		data->nb_bin = count_path_size(path, ':');
		free(path);
		return (add_bin_to_tab(tab, bin, data->nb_bin));
}
