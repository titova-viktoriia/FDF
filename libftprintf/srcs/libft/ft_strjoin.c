
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			len1;
	int			len2;
	int			i1;
	int			i2;
	char		*str;

	i1 = 0;
	i2 = 0;
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char *) * (len1 + len2 + 1))))
		return (NULL);
	while (i1 < len1)
	{
		str[i1] = s1[i1];
		i1++;
	}
	while (i2 < len2)
		str[i1++] = s2[i2++];
	str[i1] = '\0';
	return (str);
}
