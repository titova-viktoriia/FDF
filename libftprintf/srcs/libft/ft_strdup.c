
#include "libft.h"

char		*ft_strdup(const char *src)
{
	char	*src2;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(src);
	if (!(src2 = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (src[i] != '\0')
	{
		src2[i] = src[i];
		i++;
	}
	src2[i] = '\0';
	return (src2);
}
