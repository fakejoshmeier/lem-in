/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 21:23:24 by jmeier            #+#    #+#             */
/*   Updated: 2018/04/07 23:19:22 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>
#define USAGE "USAGE: ./lem-in [-D] < example.txt\n-D : Implement weight."

void	flag_check(int ac, char *av[], t_lemin *lem)
{
	if (ac > 1)
	{
		while (ac-- > 1)
		{
			if (!ft_strcmp(av[ac], "-D"))
				lem->dist = true;
			else
			{
				free(lem);
				ft_error(USAGE);
			}
		}
	}
}

void	ft_error(char *str)
{
	ft_putendl(str);
	exit(1);
}

int		main(int ac, char *av[])
{
	t_lemin	*lem;
	int		i;

	lem = (t_lemin *)ft_memalloc(sizeof(t_lemin));
	(ac < 1 || ac > 2) ? ft_error(USAGE) : 0;
	flag_check(ac, av, lem);
	begin_parse(lem, 0);
	dijkstra(-1, 0, lem->start, lem);
	!lem->end->path ? ft_error("No path between start and end found.") : 0;
	the_ants_go_marching(lem, 0);
	i = -1;
	while (++i < lem->node_amt)
	{
		free(lem->nodes[i]->links);
		free(lem->nodes[i]->name);
		free(lem->nodes[i]);
	}
	free(lem->nodes);
	free(lem);
	return (0);
}
