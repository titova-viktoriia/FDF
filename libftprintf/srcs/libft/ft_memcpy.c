
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	if (n == 0 || dst == src)
		return (dst);
	while (i < n)
	{
		(a[i] = b[i]);
		i++;
	}
	return (dst);
}
