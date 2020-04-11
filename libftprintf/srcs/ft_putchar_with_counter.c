
#include "ft_printf.h"

void	ft_putchar_with_counter(char c, t_data *data)
{
	write(1, &c, 1);
	data->len++;
}
