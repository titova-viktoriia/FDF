
#include "ft_printf.h"

void	fill_a_string_with_char(char c, char *str, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
}
