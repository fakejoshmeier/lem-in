/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 21:23:24 by jmeier            #+#    #+#             */
/*   Updated: 2018/03/25 09:55:39 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	ft_error(char *str)
{
	ft_putendl(str);
	while (1);
	exit(1);
}

int		main(int ac, char *av[])
{
	t_lemin	*lem;

	(void)av;
	if (ac < 0)
		ft_error("USAGE: ./lem-in < example.txt");
	lem = ft_memalloc(sizeof(t_lemin));
	begin_parse(lem, 0);
	write(1, "\n", 1);
	return (0);
}