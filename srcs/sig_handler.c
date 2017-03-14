/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:20:22 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/14 10:18:41 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	sig_helper(int sig)
{
	if (sig == 19 || sig == 20 || sig == 17)
		;
	else if (sig == 11)
	{
		ft_printf("\nUser closed file descriptor 0, OEF.\n");
		exit(EXIT_FAILURE);
	}
	else if (sig == 18)
	{
		ft_printf("\nCannot stop then resume Minishell, YET\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_printf("\nSignal non gere : %d, fin du programme.\n", sig);
		exit(EXIT_FAILURE);
	}
}

void	sighandler(int sig)
{
	if (sig == SIGINT)
	{
		ft_printf("\nUser pressed {:lred}Crtl + C{:reset}: Stopping.\n");
		exit(EXIT_FAILURE);
	}
	else if (sig == SIGQUIT)
	{
		ft_printf("\nSignal d'interruption\n");
		exit(EXIT_FAILURE);
	}
	else if (sig == SIGKILL)
	{
		ft_printf("\nUser kill the process: Stopping.\n");
		exit(EXIT_FAILURE);
	}
	else if (sig == SIGTERM)
	{
		ft_printf("\nTerminaison de programme\n");
		exit(EXIT_FAILURE);
	}
	else
		sig_helper(sig);
}

void	block_sig(void)
{
	int i;

	i = 0;
	while (i < 33)
		signal(i++, sighandler);
}
