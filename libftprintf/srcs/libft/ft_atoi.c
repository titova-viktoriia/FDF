
#include "libft.h"

int		ft_atoi(const char *str)
{
	long long		k;
	int				znak;

	k = 0;
	znak = 1;
	while (*str == '\n' || *str == '\v' || *str == '\t' ||
	*str == '\r' || *str == ' ' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			znak = -1;
		str++;
	}
	while (*str <= '9' && *str >= '0')
	{
		k = k * 10 + (*str - '0');
		str++;
	}
	return ((int)k * znak);
}
