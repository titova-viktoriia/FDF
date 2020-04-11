
#include "ft_printf.h"

void		print_in_while(char c, int count, t_data *data)
{
	if (c == 0)
		return ;
	if (count < 1)
		return ;
	data->len = data->len + count;
	while (count > 0)
	{
		write(1, &c, 1);
		count--;
	}
}
