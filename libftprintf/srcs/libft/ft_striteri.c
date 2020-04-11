
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	unsigned int	k;

	if (!s || !f)
		return ;
	i = 0;
	k = ft_strlen(s);
	while (k > 0)
	{
		f(i, s);
		i++;
		s++;
		k--;
	}
}
