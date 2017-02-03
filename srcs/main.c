/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:13:14 by jlasne            #+#    #+#             */
/*   Updated: 2017/02/03 16:18:15 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		main(int argc, char **argv, char **environ)
{
	(void)argc;
	(void)environ;
	(void)argv;
	//execve("/bin/ls", argv, NULL);
	ft_printf("LE DEBUT");
	return (0);
}
