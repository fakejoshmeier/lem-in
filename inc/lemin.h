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
# define LEMIN_H
# include <ft_printf.h>
# include <stdio.h>
# include <stdbool.h>

/*
** x and y are for just in case I ever decide to do a visualizer.
*/

typedef struct		s_node
{
	char			*name;
	bool			check;
	int				arrowhead;
	int				x;
	int				y;
	struct t_node	*next;
	struct s_room	**links;
}					t_node;

typedef struct		s_lemin
{
	int				ants;
	int				ants_in_start;
	int				s_flag;
	int				e_flag;
	int				node_amt;
	struct t_node	*start;
	struct t_node	*end;
	struct t_node	**nodes
}					t_lemin;


int					main(int ac, char *av[])
void				begin_parse(t_lemin *lem)
void				ft_error(char *str)

void				ants(t_lemin *lem)
void				rooms(t_lemin *lem)


int					room_check(char *str, t_lemin *lem)
void				dup_checkr(char *name, t_lemin *lem)
void				add_room(char **stuff, t_lemin *lem)
void				affix_room(t_lemin *lem, t_node *node, int node_amt)

int					count_words(char *str)
int					allnum(char *str)

#endif