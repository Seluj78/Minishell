/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:47:02 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/09 11:38:08 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 20
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_fd
{
	int				fd;
	char			*original_ptr;
	char			*current_ptr;
	struct s_fd		**begin;
	struct s_fd		*next;
	struct s_fd		*prev;
}					t_fd;

int					get_next_line(int const fd, char **line);

#endif
