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
# include <fcntl.h>

/*
** x and y are for just in case I ever decide to do a visualizer.
** Arrowhead is number of links!  I'm just being cute about it.  Can't have
** something called links without ALLOWHEDDO KAKUNIN
*/

typedef struct		s_node
{
	char			*name;
	bool			visit;
	int				arrowhead;
	int				x;
	int				y;
	struct s_node	*next;
	struct s_node	**links;
}					t_node;

/*
** This struct is purely for the purposes of parsing.  I temporarily make
** pointers to the nodes that have the same names as the ones given in the
** link, then write that information down into the node itself.  Afterwards,
** I free the struct.
*/

typedef struct		s_link
{
	char			*name0;
	char			*name1;
	struct s_node	*node0;
	struct s_node	*node1;
}					t_link;

typedef struct		s_lemin
{
	int				ants;
	int				remain;
	int				s_flag;
	int				e_flag;
	int				node_amt;
	struct s_node	*start;
	struct s_node	*end;
	struct s_node	**nodes;
}					t_lemin;


int					main(int ac, char *av[]);
void				ft_error(char *str);

/*
** parse.c
*/

void				begin_parse(t_lemin *lem, int pos);
int					ants(t_lemin *lem, char *str);
int					rooms(t_lemin *lem, char *str);
void				links(t_lemin *lem, char *str);
void				comments(char *str);

/*
** rooms.c
*/

int					room_check(char *str, t_lemin *lem);
void				dup_checkr(char *name, t_lemin *lem);
void				add_room(char **stuff, t_lemin *lem);
void				affix_room(t_lemin *lem, t_node *new_node, int node_amt);
void				command_parse(char *str, t_lemin *lem);

/*
** links.c
*/

void				arrowhead_kakunin(char *str, t_lemin *lem);
void				maaka_ni_setto(t_link *link, t_lemin *lem);
void				saaketto_konbain(t_node *uke, t_node *seme, int size);
int					dup_checkrl(t_node *node, char *link_name);

/*
** aux.c
*/

int					count_words(char *str);
int					allnum(char *str);

#endif