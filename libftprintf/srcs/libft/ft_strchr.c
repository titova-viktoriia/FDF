
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		k;

	i = ft_strlen(s) + 1;
	k = 0;
	while (k < i)
	{
		if (s[k] == (unsigned char)c)
			return ((char *)s + k);
		k++;
	}
	return (NULL);
}
