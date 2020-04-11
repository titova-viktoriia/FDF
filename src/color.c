
#include "../includes/fdf.h"

int			get_color(int p, int r, int g, int b)
{
	return ((p << 24) | (r << 16) | (g << 8) | b);
}

double		color_2(int c1, int c2, int delta, int now)
{
	double per;

	per = (double)(c2 - c1) / (double)delta;
	return (c1 + (per * now));
}

int			color(int c1, int c2, int delta, int now)
{
	int red;
	int green;
	int blue;

	if (delta == 0)
	{
		red = (c1 >> 16) & 0xFF;
		green = (c1 >> 8) & 0xFF;
		blue = c1 & 0xFF;
	}
	else
	{
		red = color_2((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, delta, now);
		green = color_2((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, delta, now);
		blue = color_2(c1 & 0xFF, c2 & 0xFF, delta, now);
	}
	return ((get_color(1, red, green, blue)));
}

void		backgraund(t_fdf *fdf)
{
	int i;

	i = 0;
	if (fdf->backgraund == 0)
		fdf->backgraund_color = BACKGRAUND_0;
	if (fdf->backgraund == 1)
		fdf->backgraund_color = BACKGRAUND_1;
	if (fdf->backgraund == 2)
		fdf->backgraund_color = BACKGRAUND_2;
	if (fdf->backgraund == 3)
		fdf->backgraund_color = BACKGRAUND_3;
	if (fdf->backgraund == 4)
		fdf->backgraund_color = BACKGRAUND_4;
	while (i <= WINDOW_X * WINDOW_Y)
	{
		fdf->data_img[i] = fdf->backgraund_color;
		i++;
	}
}
