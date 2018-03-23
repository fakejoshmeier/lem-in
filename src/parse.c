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

void	ants(t_lemin *lem)
{
	char	*str;

	while (get_next_line(0, &str))
	{
		if (str[0] == '#')
		{
			str[1] != '#' ? 0 : ft_error("Commands must precede
			 rooms, not ants");
			free(str);
			continue;
		}
		count_words(str) == 1 ? 0 : ft_error("Ants must be one number.");
		allnum(str) == 1 ? 0 : ft_error("Number of ants must be in numeric
		form.");
		lem->ants = ft_atoi(str);
		lem->ants > 0 ? 0 : ft_error("Must have at least 1 ant.  Otherwise,
		what's the point?");
		ft_putendl(str);
		free(str);
		break ;
	}
}

void	rooms(t_lemin *lem)
{
	char	*str;

	while (get_next_line(0, &str))
	{
		ft_putendl(str);
		if (str[0] == '#')
		{
			str[1] != '#' ? 0 : command_parse(str, lem);
			free(str);
			continue;
		}
		if (!room_check(str, lem))
			break ;
		free(str);
	}
	lem->node_amt ? 0 : ft_error("Must provide valid rooms!");
	lem->s_flag == 2 ? 0 : ft_error("Starting room must follow the ##start
	 command and must exist");
	lem->e_flag == 2 ? 0 : ft_error("Ending room must follow the ##end
	 command and must exist");
	free(str);
}

void	links(t_lemin *lem)
{
	char	*str;
	
	while (get_next_line(0, &str) > 0)
	{
		if (str[0] == '#')
		{
			str[1] != '#' ? 0 : ft_error("Commands only apply to rooms.");
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