
#include "libft.h"

char		*ft_strnstr(const char *hst, const char *ndl, size_t len)
{
	size_t	m;
	size_t	n;

	m = ft_strlen(ndl);
	n = ft_strlen(hst);
	if (!*ndl)
		return ((char *)hst);
	while (m <= len && n > 0)
	{
		if (*hst == *ndl)
		{
			if (ft_strncmp(hst, ndl, m) == 0)
				return ((char *)hst);
		}
		hst++;
		len--;
		n--;
	}
	return (NULL);
}
