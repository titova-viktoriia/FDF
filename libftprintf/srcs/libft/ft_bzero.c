
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*a;
	unsigned int	i;

	i = 0;
	a = (unsigned char *)s;
	while (i < n)
	{
		a[i] = 0;
		i++;
	}
}
