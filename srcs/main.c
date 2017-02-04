/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:13:14 by jlasne            #+#    #+#             */
/*   Updated: 2017/02/04 13:32:18 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
void	exec_cmd(char **cmd, char **env)
{
	(void)cmd;
	if (cmd[1] == "ls")
	  {
	  execve("/bin/ls", )
	  }
	ft_printf("%s", get_env(env, "PATH"));
}
*/

void	test_path_access(char **bin)
{
	(void)bin;
}

int		main(int argc, char **argv, char **environ)
{
	char	*line;
	char	**cmd;
	char	**bin;

	(void)argc;
	(void)argv;
	ft_printf("{:blue}[{:lred}MiniShell{:blue}] {:lgreen}➜{:reset} ");
	while (get_next_line(0, &line))
	{
		ft_printf("{:blue}[{:lred}MiniShell{:blue}] {:lgreen}➜{:reset} ");
		cmd = str_to_wordtab(line);
		bin = path_parser(environ);
		test_path_access(bin);
		//ft_printf("%d", access(bin[0], X_OK));
		//ft_printf("1 : %s   2 : %s   3 : %s", bin[0], bin[1], bin[2]);
	}
	return (0);
}
