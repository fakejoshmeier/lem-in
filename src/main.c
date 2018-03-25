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
	char	**str;
	int		pos;

	pos = 0;
	while (get_next_line(0, &str))
	{
		if (str[0] == '#' && str[1] != '#')
			ft_putendl(str);
		else if (pos == 0)
			if (ants(lem, str))
			{
				pos += 1;
				continue ;
			}
		else if (pos == 1)
			if (!rooms(lem, str))
				pos += 1;
		else if (pos == 2)
			links(lem);
		free(str);
	}
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