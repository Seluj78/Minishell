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

void	test_path_access(char **bin, int size)
{
		int i;

		i = 0;
		while (i < size)
		{
			if (access(bin[i], F_OK) != 0)
			{
					ft_printf("\nErreur : le chemin du path '%s' n'existe pas", bin[i]);
					//exit(EXIT_FAILURE);
			}
			//ft_printf("%s\n", bin[i]);
			i++;
		}
}

int		main(int argc, char **argv, char **environ)
{
		char	*line;
		char	**cmd;
		char	**bin;
		pid_t	father;

		t_data data;
		data.nb_bin = 0;
		(void)argc;
		(void)argv;
		ft_printf("{:blue}[{:lred}MiniShell{:blue}] {:lgreen}➜{:reset} ");
		while (get_next_line(0, &line))
		{
				ft_printf("{:blue}[{:lred}MiniShell{:blue}] {:lgreen}➜{:reset} ");
				cmd = str_to_wordtab(line);
				bin = path_parser(environ, &data);
				test_path_access(bin, data.nb_bin);
				father = fork();

		}
		return (0);
}

// TODO : Add cmd[0] to end of each bin[X]






/*
   -- > faire une fonction qui recupere uns a uns les paths dans cet elem
   -- > faire une fonction qui ajoute a la suite du path recupere le
   element du tableau de str_to_wordtab.
   Tester ces paths avec la fonction access. Comment elle marche ? -> man
 */

/*
   ETAPE 3 LANCER UN PROGRAMME - FORKER
   Une fois qu’on a recuperer le path, qu’on sait que c’est le bon, on va
   forker. Pourquoi ? parce qu’apres avoir lancer execve, le programme s’arrete.
   On veut arreter le programme, pas le minishell. Il faut donc duppliquer le
   prog. C’est le role de fork. Le cours explique comment il marche.
   A vous de jouer.
 */

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
