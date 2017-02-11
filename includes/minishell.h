/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:02:48 by blucas            #+#    #+#             */
/*   Updated: 2017/02/04 13:15:21 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "../libft/includes/libft.h"
# include "/usr/include/stdint.h"
# include <sys/wait.h>

char	**str_to_wordtab(char *str);
char	**str_to_tab_sep(char *str, char separator, int opt);


typedef struct  s_data
{
	int nb_bin;
}                               t_data;

char	**path_parser(char **envrion, t_data *data);
char	**add_bin_to_tab(char **tab, char *bin, int nb_bin);

#endif
