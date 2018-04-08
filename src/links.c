/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 23:58:58 by jmeier            #+#    #+#             */
/*   Updated: 2018/04/07 22:47:01 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>
#define LINK "These two rooms are already linked."

/*
** I watch WAAAAAAAAY too much Yu-Gi-Oh
*/

int		dup_checkrl(t_node *node, char *link_name)
{
	int		i;

	i = -1;
	while (++i < node->arrowhead)
	{
		if (!ft_strcmp(node->links[i]->name, link_name))
			return (1);
	}
	return (0);
}

void	saakitto_konbain(t_node *uke, t_node *seme, int size)
{
	t_node	**tmp;
	int		i;

	i = -1;
	if (!(tmp = (t_node **)ft_memalloc((sizeof(t_node*) * (size + 1)))))
		ft_error("Failed to allocate memory!");
	while (++i < size)
		tmp[i] = uke->links[i];
	tmp[i] = seme;
	if (size)
		free(uke->links);
	uke->links = tmp;
}

void	maakaa_ni_setto(t_link *link, t_lemin *lem)
{
	int		i;

	i = -1;
	while (++i < lem->node_amt)
	{
		if (!(ft_strcmp(lem->nodes[i]->name, link->name0)))
		{
			!dup_checkrl(lem->nodes[i], link->name1) ? 0 : ft_error(LINK);
			link->node0 = lem->nodes[i];
		}
		else if (!(ft_strcmp(lem->nodes[i]->name, link->name1)))
		{
			!dup_checkrl(lem->nodes[i], link->name0) ? 0 : ft_error(LINK);
			link->node1 = lem->nodes[i];
		}
		if (link->node0 && link->node1)
			break ;
	}
	if (!link->node0 || !link->node1)
		ft_error("Could not find matching rooms!");
}

void	arrowhead_kakunin(char *str, t_lemin *lem)
{
	t_link	*link;
	char	**tmp;

	if (ft_count_words(str, '-') != 2)
		ft_error("Incorrect link format. [NODE1]-[NODE2]");
	if (!(link = (t_link *)ft_memalloc(sizeof(t_link))))
		ft_error("Failed to allocate memory!");
	tmp = ft_strsplit(str, '-');
	link->name0 = tmp[0];
	link->name1 = tmp[1];
	maakaa_ni_setto(link, lem);
	saakitto_konbain(link->node0, link->node1, link->node0->arrowhead);
	saakitto_konbain(link->node1, link->node0, link->node1->arrowhead);
	++link->node0->arrowhead;
	++link->node1->arrowhead;
	ft_freearr(tmp);
	free(link);
}
