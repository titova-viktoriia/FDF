
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(size * sizeof(char))))
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
