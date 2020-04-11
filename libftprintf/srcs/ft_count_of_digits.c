
#include "ft_printf.h"

long long		ft_count_of_digits(long long n)
{
	long long			count;

	count = 1;
	if (n < 0)
		n = n * (-1);
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}
