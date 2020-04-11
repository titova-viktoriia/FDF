
#include "ft_printf.h"

void		itobufferdata(long long b, t_data *data, long long len)
{
	if (data->flag_plus == 1 && b >= 0)
		data->fl_znak = '+';
	if (b < 0)
	{
		data->fl_znak = '-';
		b = b * (-1);
	}
	if (b == 0)
		data->bufferdata[len - 1] = '0';
	while (len > 0 && b > 0)
	{
		data->bufferdata[len - 1] = b % 10 + '0';
		b = b / 10;
		len--;
	}
}
