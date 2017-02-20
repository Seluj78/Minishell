/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:13:14 by jlasne            #+#    #+#             */
/*   Updated: 2017/02/20 11:46:14 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		test_path_access(char **path, int size, char *bin)
{
	int i;
	int ok;

	ok = -1;
	i = 0;
	while (i < size)
	{
		if (access(path[i], F_OK) == 0)
		{
			ok = i;
		}
		else
		{
			if (ft_strcmp(bin, "cd") == 0)
				ok = -2;
			if (ft_strcmp(bin, "env") == 0)
				ok = -2;
			if (ft_strcmp(bin, "setenv") == 0)
				ok = -2;
			if (ft_strcmp(bin, "unsetenv") == 0)
				ok = -2;
			//TODO : -2 = builtin command

		}
		i++;
	}
	if (ok != -1)
	{
		//ft_printf("Command found in %d of path[i]\n", ok);
		return (ok);
	}
	else
	{
		if (ok == -2)
		{
			//Builtin
		}
		else
			ft_printf("Minishell : command not found: %s\n", bin);
		return (-1);
		// TODO : Add protection in case of error with the return value in  main
	}
}

void	free_chartab(char **tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int		ft_tablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != '\0')
		i++;
	return (i);
}

char	**ft_tabdup(char **tab)
{
	int i;
	int j;
	char **dup;

	j = 0;
	i = 0;
	while (tab[i] != '\0')
		i++;
	dup = malloc(i * sizeof(char *));
	while (j < i)
	{
		dup[j] = ft_strdup(tab[j]);
		j++;
	}
	return (dup);
}


// TODO : add this as ft_put_arraystring(char **array) in libft
void	ft_disp_env(char **env)
{
	int i;

	i = 0;
	while (env[i] != '\0')
	{
		ft_printf("%s\n", env[i]);
		i++;
	}
}

int		main(int argc, char **argv, char **environ)
{
	char	*line;
	char	**cmd;
	char	**path;
	char	**tmp_path;
	pid_t	pid;
	t_data data;
	int ok;

	data.nb_bin = 0;
	(void)argc;
	(void)argv;
	ft_printf("{:blue}[{:lred}MiniShell{:blue}] {:lgreen}➜{:reset} ");
	path = path_parser(environ, &data);
	while (get_next_line(0, &line))
	{
		tmp_path = ft_tabdup(path);
		cmd = str_to_wordtab(line);
		tmp_path = add_bin_to_tab(tmp_path, cmd[0], data.nb_bin);
		if (ft_strcmp(cmd[0], "exit") == 0)
			exit(EXIT_SUCCESS);
		ok = test_path_access(tmp_path, data.nb_bin, cmd[0]);
		pid = fork();
		if (pid > 0)
		{
			wait(0);
		}
		else
		{
			if (ft_strcmp(cmd[0], "cd") == 0)
				ft_printf("Command to be built : cd\n");
			else if (ft_strcmp(cmd[0], "env") == 0)
				ft_disp_env(environ);
			else if (ft_strcmp(cmd[0], "setenv") == 0)
				ft_printf("Command to be built : setenv\n");
			else if (ft_strcmp(cmd[0], "unsetenv") == 0)
				ft_printf("Command to be built : unsetenv\n");
			else
				execve(tmp_path[ok], cmd, NULL);
		}
		//TODO : Rework this free, makes program crash : free_chartab(tmp_path, ft_tablen(tmp_path));
		ft_printf("{:blue}[{:lred}MiniShell{:blue}] {:lgreen}➜{:reset} ");
	}
	free_chartab(path, data.nb_bin);
	free_chartab(cmd, ft_tablen(cmd));
	free(line);
	return (0);
}

// TODO : execute the correct command from path
// TODO : ft_exit to free correctly everything)
// TODO : Implementer cd - (go google) et du coup add oldpwd dans path
// TODO : Utiliser signal pour catch les signaux de segfault etc...

/*
   ETAPE 5 SETENV
   liste chainee : ajouter un element a la liste. A la fin de la liste. Pas
   tres difficile :) mais attention, vous devez verifier si l’element n’
   existe pas deja et si c’est le cas modifier cet element.
tableau : ajouter un element a la fin du tableau. Pour ca, il va falloir
faire un realloc, c’est a dire free(env) (sauf si c’est le tableau de depart)
malloc(la taille du tableau d’avant + 1). pareil, si l’element existe,
il faut le modifier.
*/

/*
   ETAPE 6 UNSETENV
   liste chainee : parcourir sa liste, trouver (ou pas) l’element, l’enlever.
   pop_elem_from_list (google :))
tableau : parcourir le tableau, trouver (ou pas) l’element, realloc le
tableau en enlevant l’elem.
*/

/*
   ETAPE 7 CD
   la, je me contenterait de vous dire "chdir". Et man. Et google.
   */
