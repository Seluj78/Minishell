/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:20:22 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/07 16:31:11 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

volatile int g_sig = 1;

void    sigHandle(int keep)
{
	if (keep)
	{
		g_sig = 0;
		ft_printf("\nSorry, Minishell cannot be terminated by pressing\n");
		ft_printf("{:lred}Crtl + C.{:reset}\nIf you wish to exit, please type ");
		ft_printf("{:lgreen}exit{:reset} and then press {:lblue}Enter");
		ft_printf("{:reset}\n");
		ft_printf("Else, Just keep calm and RTFM 😄\n");
		ft_printf("{:blue}[{:lred}Minishell{:blue}] {:lgreen}➜{:reset} ");
	}
}
