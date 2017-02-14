/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:13:14 by jlasne            #+#    #+#             */
/*   Updated: 2017/02/08 16:09:48 by jlasne           ###   ########.fr       */
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
			i++;
		}
		if (ok != -1)
		{
			//ft_printf("Command found in %d of path[i]\n", ok);
			return (ok);
		}
		else
		{
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
					execve(tmp_path[ok], cmd, NULL);
				}
				free_chartab(tmp_path, ft_tablen(tmp_path));
				ft_printf("{:blue}[{:lred}MiniShell{:blue}] {:lgreen}➜{:reset} ");
		}
		free_chartab(path, data.nb_bin);
		free_chartab(cmd, ft_tablen(cmd));
		free(line);
		return (0);
}

// TODO : Check for commands (cd etc...) and not display them as unknown
// TODO : execute the correct command from path
// TODO : ft_exit to free correctly everything)

/*
   ETAPE 3 LANCER UN PROGRAMME - EXECVE
   execve doit etre execute dans le fils. S’il reussit, alors il ne fera pas ce
   qu’il y a apres puisqu’il quitte. Sinon, il le fera.
   il prend en parametre le path calcule precedemment et un tableau a deux
   dimemsions vers chaque arguments exemple :
   {"ls", "-l", "-a", ".", NULL}
   ca tombe bien, c’est exectement ce qu’on a fait avec le str_to_wordtab.
   et l’environnement sous forme d’un tableau.
 */

/*
   et voila ! On a lance un programme a partir de notre minishell.
   Maintenant, on a quelques builtins a realiser.
   env, setenv et unsetenv. Le mieux serait de le faire avec des listes
   chainees. Je vous ai appris a en faire dans un precedent cours.
   Si vous n’etes pas a l’aise, vous pouvez utiliser des tableaux.
 */

/*
   ETAPE 4 ENV
   -> Si vous prenez la solution liste chainee (trop classe wahou), faites une
   fonction qui transforme le char **env en t_list *env. Cette fonction
   ressemblera a l’exo de piscine "my_params_in_list.c" (Jour 11).
   Afficher cette liste.
   -> Si vous choisissez de garder un tableau, afficher simplement ce tableau.
 */

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
