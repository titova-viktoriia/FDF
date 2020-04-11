
#include "ft_printf.h"

int				find_symbol(char c, char *macros)
{
	int		index;

	index = 0;
	while (macros[index] != '\0')
	{
		if (macros[index] == c)
			return (1);
		index++;
	}
	return (0);
}
