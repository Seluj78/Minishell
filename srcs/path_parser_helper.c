/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parser_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 11:22:34 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/09 11:23:42 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**do_absolute(void)
{
	char	**tab;

	tab = malloc(17 * sizeof(*tab));
	if (tab == NULL)
		ft_printf("Error character\n");
	tab[0] = ft_strdup("/usr/site/sbin");
	tab[1] = ft_strdup("/usr/site/bin");
	tab[2] = ft_strdup("/usr/netsoul/sbin");
	tab[3] = ft_strdup("/usr/netsoul/bin");
	tab[4] = ft_strdup("/usr/heimdal/sbin");
	tab[5] = ft_strdup("/usr/heimdal/bin");
	tab[6] = ft_strdup("/usr/arla/sbin");
	tab[7] = ft_strdup("/usr/arla/bin");
	tab[8] = ft_strdup("/usr/local/sbin");
	tab[9] = ft_strdup("/usr/local/bin");
	tab[10] = ft_strdup("/usr/sbin");
	tab[11] = ft_strdup("/usr/bin");
	tab[12] = ft_strdup("/sbin");
	tab[13] = ft_strdup("/bin");
	tab[14] = ft_strdup("/usr/sfw/bin");
	tab[15] = ft_strdup("/usr/ccs/bin");
	tab[16] = NULL;
	return (tab);
}

int		str_is_in(char *str, char *to_find)
{
	int	i;
	int	a;

	a = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while ((str[i] == to_find[a]) && ((str[i] != '\0')
					|| (to_find[a] != '\0')))
		{
			i = i + 1;
			a = a + 1;
		}
		if (to_find[a] == '\0')
			return (1);
		a = 0;
		i = i + 1;
	}
	return (0);
}
