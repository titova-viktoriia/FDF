
#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int	k;

	if (!s || !f)
		return ;
	k = ft_strlen(s);
	while (k > 0)
	{
		f(s);
		s++;
		k--;
	}
}
