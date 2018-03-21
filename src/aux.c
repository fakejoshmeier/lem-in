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

int		validate(char *str, char check)
{
	char	**tmp;

	if (check == 'r')
	{
		tmp = ft_strsplit(str, ' ');
		if (allnum(tmp[1]) && allnum(tmp[2]))
		{
			ft_freearr(tmp);
			return (1);
		}
		ft_freearr(tmp);
	}
	else if (check == 'l')
	{
		tmp = ft_strsplit(str, '-');
		if (allnum(tmp[0]) && allnum(tmp[1]) && count_words(str) == 2)
		{
			ft_freearr(tmp);
			return (1);
		}
		ft_freearr(tmp);
	}
	return (0);
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