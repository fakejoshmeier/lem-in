/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 21:23:24 by jmeier            #+#    #+#             */
/*   Updated: 2018/03/26 07:24:14 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>
#define USAGE "USAGE: ./lem-in [-D] < example.txt\n-D : Implement weight."

void	ft_error(char *str)
{
	ft_putendl(str);
	while (1);
	exit(1);
}

int		main(int ac, char *av[])
{
	t_lemin	*lem;

	lem = (t_lemin *)ft_memalloc(sizeof(t_lemin));
	if (ac < 1 || ac > 2)
		ft_error(USAGE);
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
	begin_parse(lem, 0);
	dijkstra(-1, 0, lem->start, lem);
	the_ants(lem);
	free(lem);
	return (0);
}
