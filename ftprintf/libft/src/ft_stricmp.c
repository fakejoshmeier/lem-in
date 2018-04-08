#include "libft.h"

int		ft_stricmp(char const *a, char const *b)
{
	size_t	i;
	int		j;

	i = 0;
	j = -1;
	while (a[++j])
		ft_tolower(a[j]);
	j = -1;
	while (b[++j])
		ft_tolower(b[j]);
	while (a[i] && a[i] == b[i])
		i++;
	return ((*((unsigned char *)a + i)) - (*((unsigned char *)b + i)));
}
