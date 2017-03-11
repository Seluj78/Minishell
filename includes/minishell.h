/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 10:47:27 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/11 11:48:13 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include <pwd.h>
# include <sys/types.h>
# include <sys/wait.h>
# define DPATH	"/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"

typedef struct	s_data
{
	int		nb_bin;
	char	*line;
	char	**input;
	char	**path;
	char	**full_path;
	char	**envcpy;
	char	cwd[1024];
	size_t	path_size;
}				t_data;

typedef char	t_bool;

# define TRUE 1
# define FALSE 0

char			**path_parser(char **env, t_data *data);
void			cmd_echo(char **input);
void			cmd_exec(char *exec, char **input, char **env);
void			disp_help(void);
int				command_setenv(char **argv, char ***env);
int				command_unsetenv(char **argv, char ***env);
void			cmd_cd(char **input, char ***env);
char			**ft_setenv(char *name, char *value, char **env);
void			block_sig(void);
int				ft_getenv(char *name, char **env);
char			**do_absolute(void);
int				str_is_in(char *str, char *to_find);
char			*ft_strmjoin(const size_t n, ...);
int				my_strncmp(char *s1, char *s2, int n);
void			direct_path(char **input, char ***envcpy);
size_t			ft_tabcount(void **tab);
char			**clear_bintab(char **tab, size_t size);
char			**get_bintab(char **path_tab, size_t size, const char *binstr);
void			what_cmd(char **input, char ***envcpy, \
				int size, char **tmp_path);
void			what_cmd_helper(char **tmp_path, int size, char **input,\
				char ***envcpy);
int				test_access(char **path, int size);
void			env(char ***env, char **input);
#endif
