/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 11:13:52 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/06 11:19:31 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cmd_exec(char *exec, char **input, char **env)
{
	pid_t	pid;
	pid = fork();
	if (pid > 0)
		wait(0);
	else
			execve(exec, input, env);
}
