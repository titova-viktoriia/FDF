
#include "libft.h"

static	int		count_of_digits(int n)
{
	int			count;

	count = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		count++;
		n = n * (-1);
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	char		*arr;
	int			len;
	long long	nb;

	nb = n;
	len = count_of_digits(nb);
	if (!(arr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	arr[len] = '\0';
	if (nb < 0)
	{
		arr[0] = '-';
		nb = nb * (-1);
	}
	if (n == 0)
		arr[len - 1] = '0';
	while (len > 0 && nb > 0)
	{
		arr[len - 1] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
	return (arr);
}
