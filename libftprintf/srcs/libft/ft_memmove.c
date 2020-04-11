
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	unsigned char	*a;
	unsigned char	*b;

	i = -1;
	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	if (len == 0 || dst == src)
		return (dst);
	if (a > b)
	{
		while ((int)--len >= 0)
			*(a + len) = *(b + len);
	}
	else
	{
		while (++i < len)
			*(a + i) = *(b + i);
	}
	return (dst);
}
