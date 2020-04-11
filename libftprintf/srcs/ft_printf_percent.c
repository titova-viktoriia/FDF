
#include "ft_printf.h"

void		ft_printf_percent(t_data *data)
{
	if (data->width > 1)
	{
		if (data->flag_minus == 1)
		{
			ft_putchar_with_counter('%', data);
			print_in_while(' ', data->width - 1, data);
		}
		else if (data->flag_zero == 1)
		{
			print_in_while('0', data->width - 1, data);
			ft_putchar_with_counter('%', data);
		}
		else
		{
			print_in_while(' ', data->width - 1, data);
			ft_putchar_with_counter('%', data);
		}
	}
	else
		ft_putchar_with_counter('%', data);
}
