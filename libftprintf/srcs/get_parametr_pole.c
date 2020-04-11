
#include "ft_printf.h"

void		get_parametr_pole(t_data *data, long long len)
{
	if ((data->bufferdata[0] == '0' && data->flag_dot == 1
		&& data->precision == -1) ||
		(data->bufferdata[0] == '0' && data->precision == 0) ||
		(data->bufferdata[0] == '0' && data->flag_hash == 1))
	{
		len = 0;
		data->fl_0faktor = 1;
	}
	if (data->fl_znak == 0 && data->flag_space != 0)
		data->fl_znak = ' ';
	if (data->flag_minus == 1)
		data->fl_ppole_int = 2;
	if (data->fl_znak != 0)
		data->fl_znak_int = 1;
	if (data->flag_zero == 1 && data->fl_ppole_int == 1)
		data->fl_0pole_long = data->width - len - data->fl_znak_int;
	if (data->precision >= 0)
		data->fl_0pole_long = data->precision - len;
	if (data->fl_0pole_long < 0)
		data->fl_0pole_long = 0;
	if (data->flag_hash == 1 && data->fl_0pole_long == 0)
		data->fl_0pole_long = 1;
	data->fl_ppole_long = data->width - len -
			data->fl_0pole_long - data->fl_znak_int;
}
