/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 21:23:24 by jmeier            #+#    #+#             */
/*   Updated: 2018/03/12 21:23:26 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem-in.h>

void	ft_error(char *str)
{
	ft_putendl(str);
	exit(1);
}

void	begin_parse(t_lemin *lem)
{
	ants(lem);
	rooms(lem);
	links(lem);
	write(1, "\n", 1);
}

int		main(int ac, char *av[])
{
	t_lemin	lem;

	if (ac != 1)
		ft_error("USAGE: ./lem-in < example.txt");
	ft_bzero(&lem, sizeof(t_lemin));
	begin_parse(&lem);
	return (0);
}