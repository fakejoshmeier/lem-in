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

void	command_parse(char *str, t_lemin *lem)
{
	if (ft_stricmp(str, "##start"))
		lem->s_flag = 1;
	else if (ft_stricmp(str, "##end"))
		lem->e_flag = 1;
	else
	{
		ft_putendl(str);
		ft_error("Invalid command.  Only start and end allowed")
	}
}

void	make_link(char *str, t_lemin *lem)
{
	
}

void	make_room(char *str, t_lemin *lem, t_list **tmp)
{
	char	*fug;
	t_list	*new;

	fug = ft_strsplit(str);
	if (!*tmp)
	{
		new = ft_lstnew(fug[0], ft_strlen(fug[0]));
		*tmp = new;
	}
	else
	{
		
	}

}