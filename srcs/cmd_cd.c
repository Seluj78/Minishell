/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:23:09 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/06 15:47:23 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	ft_strclen(const char *str, int c)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

char	*getcharenv(char **env, char *name)
{
	char	*ret;

	while (*env && ft_strncmp(name, *env, ft_strclen(*env, '=')))
		env++;
	if (!*env)
		return (NULL);
	if ((ret = ft_strchr(*env, '=')))
		return (ret + 1);
	return (*env);
}

void	oldpwd(char **env)
{
	chdir(getcharenv(env, "OLDPWD"));
}

void	cmd_cd(char **input, char ***env)
{
	if (input[1] == NULL)
	{
		*env = ft_setenv("OLDPWD", getcharenv(*env, "PWD"), *env);
		chdir(getcharenv(*env, "HOME"));
	}
	else if (ft_strcmp(input[1], "-") == 0)
		oldpwd(*env);
	else
	{
		*env = ft_setenv("OLDPWD", getcharenv(*env, "PWD"), *env);
		chdir(input[1]);
	}
}
