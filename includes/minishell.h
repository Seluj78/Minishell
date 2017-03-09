/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 10:47:27 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/09 11:01:26 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include <pwd.h>
# include <sys/types.h>
# include <sys/wait.h>
# define DPATH	"/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"

typedef struct  s_data
{
	int nb_bin;
}                               t_data;

/*
 * ** Typedefs :
 * */

typedef char		t_bool;

/*
 * **Defines relative to typedefs
 * */

# define TRUE 1
# define FALSE 0

char	**path_parser(char **env, t_data *data);
char **add_bin_to_tab(char **tab, char *bin, int nb_bin);
void	cmd_echo(char **input);
void	cmd_exec(char *exec, char **input, char **env);
void	disp_help(void);
int		command_setenv(char **argv, char ***env);
int		command_unsetenv(char **argv, char ***env);
void	cmd_cd(char **input, char ***env);
char		**ft_setenv(char *name, char *value, char **env);
void    sigHandle(int keep);
int             ft_getenv(char *name, char **env);
#endif
