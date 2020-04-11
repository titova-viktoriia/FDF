
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*a;

	i = 0;
	a = (unsigned char *)b;
	if (len == 0)
		return (b);
	while (i < len)
	{
		a[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
