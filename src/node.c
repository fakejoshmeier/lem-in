/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 19:51:40 by jmeier            #+#    #+#             */
/*   Updated: 2018/03/21 19:51:42 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

t_node	*ft_newnode(void const *content, size_t content_size)
{
	t_node	*tmp;

	if (!tmp = (t_node*)malloc(sizeof(t_node)))
		return (NULL);
	if (!content)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
	}
	else
	{
		if (!tmp->content = malloc(content_size))
		{
			free(tmp);
			return (NULL);
		}
		ft_memcpy(tmp->content, (void *)content, content_size);
		tmp->content_size = content_size;
	}
	tmp->next = NULL;
	return (tmp);
}

void	ft_iternode(t_node *lst, char *str)
{
	if (!lst)
		return ;
	if (lst->next)
		ft_iternode(lst->next, f);
	if (!ft_strcmp(lst->name, str))
	{
		ft_putendl(str);
		ft_error("Duplicate room name!");
	}
}
