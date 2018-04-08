/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 19:51:54 by jmeier            #+#    #+#             */
/*   Updated: 2018/04/07 22:21:41 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	command_parse(char *str, t_lemin *lem)
{
	if (!ft_strcmp(str, "##start") && !lem->s_flag)
		lem->s_flag = 1;
	else if (!ft_strcmp(str, "##end") && !lem->e_flag)
		lem->e_flag = 1;
	else if ((!ft_strcmp(str, "##start") && lem->s_flag) ||\
	(!ft_strcmp(str, "##end") && lem->e_flag))
		ft_error("Cannot have more than one start/end command each");
	else
		ft_error("Invalid command.  Only start and end allowed");
}

void	dup_checkr(char *name, t_lemin *lem)
{
	int		i;

	i = -1;
	while (++i < lem->node_amt)
	{
		ft_strcmp(name, lem->nodes[i]->name) != 0 ? 0 :
			ft_error("Two rooms with the same name?  Blasphemy!");
	}
}

void	affix_room(t_lemin *lem, t_node *new_node, int node_amt)
{
	t_node	**tmp;
	int		i;

	i = -1;
	if (node_amt == 0)
	{
		if (!(lem->nodes = (t_node**)ft_memalloc(sizeof(t_node *))))
			ft_error("Unable to allocate memory!");
		lem->nodes[0] = new_node;
	}
	else
	{
		if (!(tmp = (t_node**)ft_memalloc(sizeof(t_node *) * (node_amt + 1))))
			ft_error("Unable to allocate memory!");
		while (++i < node_amt)
			tmp[i] = lem->nodes[i];
		tmp[i] = new_node;
		free(lem->nodes);
		lem->nodes = tmp;
	}
}

void	add_room(char **stuff, t_lemin *lem)
{
	t_node	*node;

	if (!(node = (t_node *)ft_memalloc(sizeof(t_node))))
		ft_error("Unable to allocate memory!");
	node->name = ft_strdup(stuff[0]);
	node->row = (double)ft_atoi(stuff[1]);
	node->col = (double)ft_atoi(stuff[2]);
	node->visit = false;
	node->weight = INFINITY;
	if (lem->s_flag == 1)
	{
		lem->start = node;
		lem->s_flag = 2;
		node->start = 1;
		node->weight = 0;
	}
	if (lem->e_flag == 1)
	{
		lem->end = node;
		node->end = 1;
		lem->e_flag = 2;
	}
	affix_room(lem, node, lem->node_amt);
	++lem->node_amt;
}

int		room_check(char *str, t_lemin *lem)
{
	char	**tmp;

	if (ft_count_words(str, ' ') != 3)
		return (0);
	tmp = ft_strsplit(str, ' ');
	if (!allnum(tmp[1]) || !allnum(tmp[2]))
		ft_error("Given coordinates must be numerals.");
	dup_checkr(tmp[0], lem);
	add_room(tmp, lem);
	ft_freearr(tmp);
	return (1);
}
