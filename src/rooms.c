/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 19:51:54 by jmeier            #+#    #+#             */
/*   Updated: 2018/03/21 19:52:00 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	command_parse(char *str, t_lemin *lem)
{
	if (ft_stricmp(str, "##start") && !lem->s_flag)
		lem->s_flag = 1;
	else if (ft_stricmp(str, "##end") && !lem->e_flag)
		lem->e_flag = 1;
	else
		ft_error("Invalid command.  Only start and end allowed")
}

void	dup_checkr(char *name, t_lemin *lem)
{
	int		i;

	i = -1;
	while (++i < lem->node_amt)
		ft_strcmp(name, lem->nodes[i]->name) != 0 ? 0 :
			ft_error("Two rooms with the same name?  Blasphemy!");
}

void	affix_room(t_lemin *lem, t_node *node, int node_amt)
{
	t_node	**tmp;
	int		i;

	i = -1;
	if (node_amt == 0)
	{
		tmp = ft_memalloc(sizeof(t_node *));
		tmp[0] = node;
		lem->nodes = tmp;
	}
	else
	{
		if (!tmp = ft_memalloc(sizeof(t_node *) * (node_amt + 1)))
			ft_error("Unable to allocate memory!");
		while (++i < node_amt)
			tmp[i] = lem->nodes[i];
		tmp[i] = node;
		free(lem->nodes);
		lem->nodes = tmp;
	}
}

void	add_room(char **stuff, t_lemin *lem)
{
	t_node	*node;

	if (!node = ft_memalloc(sizeof(node)))
		ft_error("Unable to allocate memory!");
	node->name = ft_strdup(stuff[0]);
	node->weight = 1;
	node->x = ft_atoi(stuff[2]);
	node->y = ft_atoi(stuff[1]);
	affix_room(lemin, node, lem->node_amt);
	++lem->node_amt;
}

int		room_check(char *str, t_lemin *lem)
{
	char	**tmp;

	if (count_words(str) != 3)
		return (0);
	tmp = ft_strsplit(str, ' ');
	if (!allnum(tmp[1]) || !allnum(tmp[2]))
		ft_error("Given coordinates must be numerals.");
	dup_checkr(tmp[0], lem);
	add_room(tmp, lem);
	ft_freearr(tmp);
	return (1);
}
