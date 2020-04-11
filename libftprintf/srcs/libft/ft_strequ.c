
#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int res;

	if (!s1 || !s2)
		return (0);
	res = ft_strcmp(s1, s2);
	if (res == 0)
		return (1);
	else
		return (0);
}
