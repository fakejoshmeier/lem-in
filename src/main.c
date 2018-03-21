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
	char	*str;
	t_list	*tmp;

	while (get_next_line(0, &str))
	{
		if (str[0] == '#')
			if (str[1] == '#')
				command_parse(str, lem);
		else if (count_words(str) == 1)
		{
			ft_strchr(str, '-') && validate(str, 'l') ? make_link(str, lem) : 0;
			lem->ants = ft_allnum(str) ? ft_atoi(str) : 0;
		}
		else if (word_count(str) == 3)
			validate(str, 'r') ? make_room(str, lem, &tmp) : 0;
		ft_putendl(str);
	}
	write(1, "\n", 1);
}

// input_assembly will run a parser suite.  Create a buffer after running GNL once
// Free that buffer after it gets printed
// Create flags for start found,
// Create flags for end found, 
// create flags for ants found,
// Create doubly linked lists?  Need to look up how graphs are made and how to traverse
// FD is 0!  Reading rom stdin because it gets piped into the whatever this is called

int		main(int ac, char *av[])
{
	t_lemin	lem;

	if (ac != 1)
		ft_error("USAGE: ./lem-in < example.txt");
	begin_parse(&lem);
	return (0);
}