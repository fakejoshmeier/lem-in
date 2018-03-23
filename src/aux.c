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
	int		i;
	char	**tmp;

	i = -1;
	tmp = ft_strsplit(str, ' ');
	while (str[++i])
		;
	ft_freearr(tmp);
	return (i);
}

int		allnum(char *str)
{
	int 	i;
	int		yes;
	
	i = -1;
	while (str[++i])
	{
		yes = ft_isdigit(str[i]) ? 1 : 0;
		if (yes == 0)
			ft_putendl(str);
			ft_error("Input is invalid");
	}
	return (1);
}
