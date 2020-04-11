
#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*str;

	if (size + 1 == 0)
		return (NULL);
	if (size == 0)
		return (NULL);
	str = ft_memalloc(size + 1);
	if (!(str))
		return (NULL);
	return (str);
}
