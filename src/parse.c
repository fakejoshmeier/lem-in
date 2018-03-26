/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 23:53:02 by jmeier            #+#    #+#             */
/*   Updated: 2018/03/26 07:24:17 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	comments(char *str)
{
	ft_putendl(str);
	free(str);
}

int		ants(t_lemin *lem, char *str)
{
	str[0] == '#' && str[1] == '#' ? ft_error("Commands only apply to rooms.")
	: 0;
	count_words(str) == 1 ? 0 : ft_error("Ants must be one number.");
	allnum(str) ? 0 : ft_error("Number of ants must be in numeric form.");
	lem->ants = ft_atoi(str);
	lem->ants > 0 ? 0 : ft_error("Must have at least 1 ant.  Otherwise, what's \
	the point?");
	ft_putendl(str);
	free(str);
	return (1);
}

int		rooms(t_lemin *lem, char *str)
{
	if (str[0] == '#' && str[1] == '#')
		command_parse(str, lem);
	else if (!room_check(str, lem))
	{
		lem->node_amt ? 0 : ft_error("Must provide valid rooms!");
		lem->start ? 0 : ft_error("Starting room must follow the ##start \
			command and must exist.");
		lem->end ? 0 : ft_error("Ending room must follow the ##end \
			command and must exist.");
		return (0);
	}
	ft_putendl(str);
	return (1);
}

void	links(t_lemin *lem, char *str)
{
	str[0] == '#' && str[1] == '#' ? ft_error("Commands only apply to rooms.")
	: 0;
	if ((count_words(str) != 1) || !(ft_strchr(str, '-')))
		ft_error("Invalid link format.");
	arrowhead_kakunin(str, lem);
	ft_putendl(str);
}

void	begin_parse(t_lemin *lem, int pos)
{
	char	*str;

	while (get_next_line(0, &str))
	{
		if (str[0] == '#' && str[1] != '#')
		{
			comments(str);
			continue ;
		}
		else if (pos == 0)
		{
			if (ants(lem, str))
			{
				pos += 1;
				continue ;
			}
		}
		else if (pos == 1)
			if (!rooms(lem, str))
				pos += 1;
		if (pos == 2)
			links(lem, str);
		free(str);
	}
}
