/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 23:53:02 by jmeier            #+#    #+#             */
/*   Updated: 2018/03/15 23:53:06 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		ants(t_lemin *lem, char *str)
{
	count_words(str) == 1 ? 0 : ft_error("Ants must be one number.");
	allnum(str) == 1 ? 0 : ft_error("Number of ants must be in numeric form.");
	lem->ants = ft_atoi(str);
	lem->ants > 0 ? 0 : ft_error("Must have at least 1 ant.  Otherwise, what's
	 the point?");
	ft_putendl(str);
	return (1);
}

int		rooms(t_lemin *lem, char *str)
{
	if (str[0] == '#' && str[1] == '#')
		command_parse(str, lem);
	else if (!room_check(str, lem))
	{
		lem->node_amt ? 0 : ft_error("Must provide valid rooms!");
		lem->s_flag == 2 ? 0 : ft_error("Starting room must follow the ##start
	 	command and must exist");
		lem->e_flag == 2 ? 0 : ft_error("Ending room must follow the ##end
	 	command and must exist");
		return (0);
	}
	ft_putendl(str);
	return (1);
}

void	links(t_lemin *lem, char *str)
{
	char	*str;
	
	while (get_next_line(0, &str) > 0)
	{
		if (str[0] == '#')
		{
			str[1] != '#' ? ft_putendl(str) :
			ft_error("Commands only apply to rooms.");
			continue;
		}
		else
		{
			if (count_words(str) != 1)
				ft_error("Invalid link format.")
			link_to_room(str, lem);
		}
		ft_putendl(str);
		free(str);
	}
}