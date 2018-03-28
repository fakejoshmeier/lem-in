/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 19:49:13 by jmeier            #+#    #+#             */
/*   Updated: 2018/03/26 07:24:09 by jmeier           ###   ########.fr       */
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

	i = -1;
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

double	sqroot(double square)
{
	double	root;
	int		i;

	root = square / 3;
	i = -1;
	if (square <= 0)
		return (0);
	while (++i < 32)
		root = (root + square / root) / 2;
	return (root);
}

double	distance(t_node *a, t_node *b)
{
	double	x;
	double	y;

	x = (a->row - b->row);
	y = (a->col - b->col);
	return (sqroot((x * x) + (y * y)));
}
