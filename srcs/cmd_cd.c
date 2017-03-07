/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:23:09 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/07 14:09:58 by jlasne           ###   ########.fr       */
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


void	cmd_cd(char **input, char ***env)
{
	char cwd[1024];

	if (input[1] == NULL)
	{
		*env = ft_setenv("OLDPWD", getcharenv(*env, "PWD"), *env);
		if (chdir(getcharenv(*env, "HOME")) == -1)
			ft_printf("cd: HOME not set\n");
	}
	else if (ft_strcmp(input[1], "-") == 0)
	{
		char *tmp = getcharenv(*env, "PWD");
		chdir(getcharenv(*env, "OLDPWD"));
		*env = ft_setenv("OLDPWD", tmp, *env);
	}
	else
	{
		*env = ft_setenv("OLDPWD", getcharenv(*env, "PWD"), *env);
		if (chdir(input[1]) == -1)
			ft_printf("cd: no such file or directory: %s\n", input[1]);
	}
	getcwd(cwd, sizeof(cwd));
	*env = ft_setenv("PWD", cwd, *env);
}
