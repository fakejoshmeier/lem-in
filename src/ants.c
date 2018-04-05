/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:56:31 by jmeier            #+#    #+#             */
/*   Updated: 2018/03/29 12:34:16 by josh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	hurrah_hurrah(unsigned int ants_in_end, t_node *tmp, t_lemin *lem)
{
	tmp->path->ant = tmp->ant + 1;
	if ((tmp->path->ant - 1) != ants_in_end)
		write(1, " ", 1);
	ft_printf("L%d-%s", tmp->path->ant, tmp->path->name);
	--lem->remain;
}

void	go_marching_one_by_one(unsigned int ants_in_end, t_lemin *lem)
{
	t_node		*tmp;


	while (ants_in_end < lem->ants)
	{
		tmp = lem->end;
		while (tmp->path)
		{
			if (tmp->end && tmp->ant)
				++ants_in_end;
			if ((tmp->ant = tmp->path->ant))
			{
				tmp->ant - 1 != ants_in_end ? write(1, " ", 1) : 0;
				ft_printf("L%i-%s", tmp->ant, tmp->name);
			}
			if (tmp->path->start && !lem->remain)
				tmp->path->ant = 0;
			if (tmp->path->start && lem->remain > 0)
				hurrah_hurrah(ants_in_end, tmp, lem);
			tmp = tmp->path;
		}
		write(1, "\n", 1);
	}
}

void	the_ants(t_lemin *lem)
{
	lem->remain = lem->ants;
	go_marching_one_by_one(0, lem);
}
