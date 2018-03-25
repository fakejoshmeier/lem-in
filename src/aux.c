/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 19:49:13 by jmeier            #+#    #+#             */
/*   Updated: 2018/03/21 19:49:19 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		count_words(char *str)
{
	int		count;
	int		i;
	char	c;

	c = ' ';
	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

int		ignore(char c)
{
	if ((c >= '0' && c <= '9') || c == '\n')
		return (1);
	return (0);
}

int		allnum(char *str)
{
	int 	i;
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
