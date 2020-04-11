
#include "ft_printf.h"

int		**ft_new_arr_i(int a, int b)
{
	int		**masi;
	int		i;

	masi = (int **)malloc(sizeof(int*) * (a));
	i = 0;
	while (i < a)
	{
		masi[i] = (int *)malloc(sizeof(int) * b);
		i++;
	}
	return (masi);
}
