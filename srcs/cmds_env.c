/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:30:20 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/09 14:02:42 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			ft_getenv(char *name, char **env)
{
	int		i;
	char	*search;
	int		name_len;

	name_len = ft_strlen(name) + 2;
	search = (char*)malloc(sizeof(char) * name_len);
	if (search != NULL)
	{
		ft_strcpy(search, name);
		ft_strcat(search, "=");
		i = 0;
		while (env[i] != NULL)
		{
			if (my_strncmp(env[i], search, name_len) == 0)
			{
				free(search);
				return (i);
			}
			i = i + 1;
		}
		free(search);
	}
	return (-1);
}

char		**ft_setenv(char *name, char *value, char **env)
{
	int		i;
	int		total_len;
	char	*record;

	total_len = ft_strlen(name) + ft_strlen(value) + 2;
	record = (char*)malloc(sizeof(char) * total_len);
	if (record != NULL)
	{
		ft_strcpy(record, name);
		ft_strcat(record, "=");
		ft_strcat(record, value);
		if ((i = ft_getenv(name, env)) >= 0)
		{
			free(env[i]);
			env[i] = record;
		}
		else
			return (ft_add_to_array(record, env));
	}
	return (env);
}

char		**ft_unsetenv(char *name, char **env)
{
	int		i;

	if ((i = ft_getenv(name, env)) >= 0)
	{
		env = ft_remfrom_array(i, env);
	}
	return (env);
}

int			command_setenv(char **argv, char ***env)
{
	if (argv[1] != NULL)
	{
		if (argv[2] != NULL)
			*env = ft_setenv(argv[1], argv[2], *env);
		else
			*env = ft_setenv(argv[1], "", *env);
	}
	else
		ft_printf("setenv: Too few arguments.\n");
	return (1);
}

int			command_unsetenv(char **argv, char ***env)
{
	if (argv[1] != NULL)
		*env = ft_unsetenv(argv[1], *env);
	else
		ft_printf("unsetenv: Too few arguments.\n");
	return (1);
}
