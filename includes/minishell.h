/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 10:47:27 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/06 15:15:04 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"

typedef struct  s_data
{
	int nb_bin;
}                               t_data;

char	**path_parser(char **env, t_data *data);
char **add_bin_to_tab(char **tab, char *bin, int nb_bin);
void	cmd_echo(char **input);
void	cmd_exec(char *exec, char **input, char **env);
void	disp_help(void);
int		command_setenv(char **argv, char ***env);
int		command_unsetenv(char **argv, char ***env);
void	cmd_cd(char **input, char ***env);
char		**ft_setenv(char *name, char *value, char **env);

#endif
