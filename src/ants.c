/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:56:31 by jmeier            #+#    #+#             */
/*   Updated: 2018/04/07 22:25:54 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

/*
** So it looks as if the ants work on a sort of queue?  I run through the things
** in what looks to be a while loop.  So while
*/

void	one_small_step_for_an_ant(int finished, t_node *second, t_lemin *lem)
{
	second->path->ant_in_node = second->ant_in_node + 1;
	second->path->ant_in_node - 1 != finished ? write(1, " ", 1) : 0;
	ft_printf("L%i-%s", second->path->ant_in_node, second->path->name);
	--lem->remain;
}

void	the_ants_go_marching(t_lemin *lem, int finished)
{
	t_node	*tmp;

	while (finished < lem->ants)
	{
		tmp = lem->end;
		while (tmp->path)
		{
			if (tmp->end && tmp->ant_in_node)
				++finished;
			tmp->ant_in_node = tmp->path->ant_in_node;
			if (tmp->ant_in_node)
			{
				tmp->ant_in_node - 1 != finished ? write(1, " ", 1) : 0;
				ft_printf("L%i-%s", tmp->ant_in_node, tmp->name);
			}
			if (tmp->path->start)
				!lem->remain ? (tmp->path->ant_in_node = 0) : \
				one_small_step_for_an_ant(finished, tmp, lem);
			tmp = tmp->path;
		}
		if (finished == lem->ants)
			break ;
		write(1, "\n", 1);
	}
}
