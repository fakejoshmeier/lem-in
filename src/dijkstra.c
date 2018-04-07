/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:59:53 by jmeier            #+#    #+#             */
/*   Updated: 2018/03/29 11:17:25 by josh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

/*
** Dijkstra's might be overkill considering how each edge is weighted at one
** since the grading sheet doesn't take distance into account :/
** I saved the values for rows and columns and so theoretically could add
** weight as a parameter, but I'm not allowed to use math.h's sqrt function.
** Oh dunk, the Babylonian method exists, so I have a relatively easy way to
** make distance...UUUUGH, I guess I'll do it?  It technically becomes a more
** complete implementation of the project since it really does find the
** shortest possible path.  Oh shit, make this a flag.  Default weight as 1,
** but if you want to get FANCY, pop in that -D ( ͡° ͜ʖ ͡°) and I'll use
** distance.
*/

/*
** Depending on the dist flag, if marked as true, then distance will be
** given in the distance formula.  Else, I'll just make distance equal to 1
*/

int		youre_gonna_carry_that_weight(t_node *curr, t_node *next, bool flag)
{
	float	dist;
	float	weight;

	if (next->start)
	{
		printf("%s %f\n", curr->name, next->weight);
		return (0);
	}
	dist = (flag == true) ? distance(curr, next) : 1;
	weight = curr->weight;
	if (next->path && weight + dist < next->weight)
	{
		next->weight = weight + dist;
		return (1);
	}
	if (!next->path)
	{
		next->weight = weight + dist;
		return (1);
	}
	return (0);
}

void	dijkstra(int i, int step, t_node *node, t_lemin *lem)
{
	while (++i < node->arrowhead && step < 2)
	{
		node->visit = true;
		if (!step)
		{
			if (youre_gonna_carry_that_weight(node, node->links[i], lem->dist))
				node->links[i]->path = node;
		}
		else
		{
			if (!node->end && !node->links[i]->start && !node->links[i]->visit)
				dijkstra(-1, 0, node->links[i], lem);
		}
		if (i == node->arrowhead - 1)
		{
			++step;
			i = -1;
		}
	}
}