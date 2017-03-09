/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:32:11 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/09 14:10:28 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

void					free_chain(t_fd *fdptr)
{
	if (fdptr->prev)
		fdptr->prev->next = fdptr->next;
	else
		*fdptr->begin = fdptr->next;
	if (fdptr->next)
		fdptr->next->prev = fdptr->prev;
	free(fdptr->original_ptr);
	free(fdptr);
}

t_fd					*get_fd_ptr(int fd)
{
	static t_fd			*fd_chaine_list = NULL;
	t_fd				*fdptr;

	fdptr = fd_chaine_list;
	while (fdptr && fdptr->fd != fd)
		fdptr = fdptr->next;
	if (!fdptr)
	{
		fdptr = (t_fd*)malloc(sizeof(t_fd));
		fdptr->fd = fd;
		fdptr->original_ptr = NULL;
		fdptr->current_ptr = NULL;
		fdptr->next = fd_chaine_list;
		fdptr->prev = NULL;
		fdptr->begin = &fd_chaine_list;
		if (fd_chaine_list)
			fd_chaine_list->prev = fdptr;
		fd_chaine_list = fdptr;
	}
	return (fdptr);
}

void					set_fd_ptr(int size, char *buf, t_fd *fdptr, int i)
{
	char				*tmp;

	tmp = (char *)malloc(sizeof(char) * (size + i + 1));
	i = 0;
	while (fdptr->current_ptr && fdptr->current_ptr[i])
	{
		tmp[i] = fdptr->current_ptr[i];
		i++;
	}
	if (fdptr->original_ptr)
		free(fdptr->original_ptr);
	fdptr->original_ptr = tmp;
	fdptr->current_ptr = tmp;
	tmp += i;
	i = 0;
	while (i < size)
	{
		tmp[i] = buf[i];
		i++;
	}
	tmp[i] = '\0';
}

int						get_line(t_fd *fdptr, char **line)
{
	int					i;

	i = 0;
	while (fdptr->current_ptr && fdptr->current_ptr[i] &&
			fdptr->current_ptr[i] != '\n')
		i++;
	if (fdptr->current_ptr && fdptr->current_ptr[i] == '\n')
	{
		fdptr->current_ptr[i] = '\0';
		*line = fdptr->current_ptr;
		fdptr->current_ptr += i + 1;
		return (-1);
	}
	return (i);
}

int						get_next_line(int fd, char **line)
{
	t_fd				*fdptr;
	char				buf[BUFFER_SIZE];
	int					i;
	int					size;

	i = 0;
	size = 0;
	fdptr = get_fd_ptr(fd);
	if ((i = get_line(fdptr, line)) == -1)
		return (1);
	size = (int)read(fd, buf, BUFFER_SIZE);
	if (size == 0 && fdptr->current_ptr && fdptr->current_ptr[0] != '\0')
	{
		*line = fdptr->current_ptr;
		fdptr->current_ptr += i;
		return (1);
	}
	if (size <= 0)
	{
		free_chain(fdptr);
		return (size);
	}
	set_fd_ptr(size, buf, fdptr, i);
	return (get_next_line(fd, line));
}
