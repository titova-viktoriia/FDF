
#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned int index;

	index = 0;
	while (index < len && src[index] != '\0')
	{
		dst[index] = src[index];
		index++;
	}
	while (index < len)
	{
		dst[index] = '\0';
		index++;
	}
	return (dst);
}
