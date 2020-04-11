
#include "ft_printf.h"

char		**ft_new_ar_c(int a, int b)
{
	char	**mas;
	int		i;

	mas = (char **)malloc(sizeof(char*) * (a));
	i = 0;
	while (i < a)
	{
		mas[i] = (char *)malloc(sizeof(char) * b);
		i++;
	}
	return (mas);
}
