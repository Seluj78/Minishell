/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 19:24:20 by jlasne            #+#    #+#             */
/*   Updated: 2016/12/16 11:38:14 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdarg.h>

/*
** Typedefs :
*/

typedef char		t_bool;

/*
**Defines relative to typedefs
*/

# define TRUE 1
# define FALSE 0
# define LONG_MAX 2147483647
# define LONG_MIN -2147483647

/*
**Structs :
*/

typedef struct	s_data
{
	va_list		*ap;
	char		*format;
	int			l_format;
	char		type;
	int			ret;
	int			index;
	int			nb_len;
	char		*conv;
	char		c;
	t_bool		is_l;
	t_bool		is_ll;
	t_bool		is_h;
	t_bool		is_hh;
	t_bool		is_j;
	t_bool		is_z;
	t_bool		has_hashtag;
	t_bool		moinsloc;
	t_bool		plusloc;
	t_bool		is_prec;
	t_bool		check_spaces;
}				t_data;

#endif
