/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 11:31:08 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/09 11:33:48 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int main(int argc, char **argv)
{
	int fd;
	char *line;
	fd = open("Makefile", O_RDONLY);

	get_next_line(fd, &line);
	ft_printf("%s\n", line);

}
