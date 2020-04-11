
#include "../includes/fdf.h"

static void		zalivka(int *image, int x, int y, int color)
{
	int	i;

	i = 0;
	while (i < y)
	{
		image[x++] = color;
		i++;
	}
}

static void		backgraund_menu(int *image, int x)
{
	while (x < MENU * 50)
		image[x++] = BACKGRAUND_0;
	while (x < MENU * 100)
	{
		zalivka(image, x, 70, BACKGRAUND_1);
		zalivka(image, x + 70, MENU - 70, BACKGRAUND_2);
		x = x + MENU;
	}
	while (x < MENU * MENU)
	{
		zalivka(image, x, 70, BACKGRAUND_3);
		zalivka(image, x + 70, MENU - 70, BACKGRAUND_4);
		x = x + MENU;
	}
}

static void		mode_menu(int *image, int x)
{
	while (x < MENU * 50)
		image[x++] = BACKGRAUND_0;
	while (x < MENU * 55)
		image[x++] = BACKGRAUND_4;
	while (x < MENU * 95)
	{
		zalivka(image, x, 5, BACKGRAUND_4);
		zalivka(image, x + 5, MENU - 10, BACKGRAUND_0);
		zalivka(image, x + MENU - 5, 5, BACKGRAUND_4);
		x = x + MENU;
	}
	while (x < MENU * 100)
		image[x++] = BACKGRAUND_4;
	while (x < MENU * (MENU - 5))
	{
		zalivka(image, x, 5, BACKGRAUND_4);
		zalivka(image, x + 5, MENU - 10, BACKGRAUND_0);
		zalivka(image, x + MENU - 5, 5, BACKGRAUND_4);
		x = x + MENU;
	}
	while (x < MENU * MENU)
		image[x++] = BACKGRAUND_4;
}

static void		color_menu(int *image, int x)
{
	while (x < MENU * 50)
	{
		zalivka(image, x, 50, BACKGRAUND_0);
		zalivka(image, x + 50, MENU - 50, BACKGRAUND_1);
		zalivka(image, x + 100, MENU - 100, BACKGRAUND_3);
		x = x + MENU;
	}
	while (x < MENU * 100)
	{
		zalivka(image, x, 50, 16711680);
		zalivka(image, x + 50, MENU - 50, 2046381);
		zalivka(image, x + 100, MENU - 100, 16763904);
		x = x + MENU;
	}
}

void			menu_1(t_fdf *fdf)
{
	backgraund_menu(fdf->data_img_menu, 0);
	mode_menu(fdf->data_img_mode_menu, 0);
	color_menu(fdf->data_img_col_menu, 0);
	mlx_put_image_to_window(fdf->mlx, fdf->win,
			fdf->image_menu, 0, 0);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image_mode_menu,
			WINDOW_X - MENU, 0);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image_col_menu,
			0, WINDOW_Y - MENU + 50);
	mlx_string_put(fdf->mlx, fdf->win, 20, 10,
			16711935, "Backgraund");
	mlx_string_put(fdf->mlx, fdf->win, 5, WINDOW_Y - MENU - 30,
			16711935, "Color of lines:");
	mlx_string_put(fdf->mlx, fdf->win, 5, WINDOW_Y - MENU - 10,
			16711935, "Left_mouse - LOW");
	mlx_string_put(fdf->mlx, fdf->win, 5, WINDOW_Y - MENU + 10,
			16711935, "Right_mouse - HIGH");
	mlx_string_put(fdf->mlx, fdf->win, 20 + WINDOW_X - MENU,
			10, 16711935, "Mode mouse");
	mlx_string_put(fdf->mlx, fdf->win, 20 + WINDOW_X - MENU,
			60, 16711935, "Zoom all");
	mlx_string_put(fdf->mlx, fdf->win, 20 + WINDOW_X - MENU,
			110, 16711935, "Zoom height");
}
