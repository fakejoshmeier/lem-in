/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 21:02:52 by jmeier            #+#    #+#             */
/*   Updated: 2018/03/12 21:02:55 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define lemin.h
#include <ft_printf.h>
#include <stdio.h>

/*
** t_lemin has the information about the lemin.  Ants
*/

typedef struct	s_lemin
{
	int			ants;
	int			s_flag;
	int			e_flag;
	
	t_node		*start;
	t_node		*end;
}				t_lemin;

typedef struct	s_node
{
	char		*name;
	t_node		*next;
}				t_node;

int				main(void)

#endif