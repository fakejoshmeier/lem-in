/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 23:58:58 by jmeier            #+#    #+#             */
/*   Updated: 2018/03/22 23:59:01 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	addlink_to_room(t_node *node, t_node *link, int array_size)
{
	t_node	**tmp;
	int		i;

	i = -1;
	if (!(tmp = (t_room **)ft_memalloc(array_size + 1)))
		ft_error("Failed to allocate memory!");
	while (++i < array_size)
		tmp[i] = room->links[i];
	tmp[i] = link;
	if (array_size)
		free(room->links);
	room->links = newarray;
}
