/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 19:49:13 by jmeier            #+#    #+#             */
/*   Updated: 2018/04/08 13:56:06 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	free_lots(void *ptr1, void *ptr2)
{
	free(ptr1);
	free(ptr2);
}

int		ignore(char c)
{
	if ((c >= '0' && c <= '9') || c == '\n')
		return (1);
	return (0);
}

int		allnum(char *str)
{
	int		i;
	int		yes;

	i = (str[0] == '-') ? 1 : 0;
	while (str[++i])
	{
		yes = ignore(str[i]) ? 1 : 0;
		if (yes == 0)
			return (0);
	}
	return (1);
}

/*
** This function is based on the Babylonian method.
*/

double	distance(t_node *a, t_node *b)
{
	double	x;
	double	y;

	x = (a->row - b->row);
	y = (a->col - b->col);
	return (ft_sqroot((x * x) + (y * y)));
}
