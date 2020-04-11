
#include "../includes/fdf.h"

void			image_menu(t_fdf *fdf)
{
	if (ft_strlen(fdf->argv) < 25)
	{
		mlx_string_put(fdf->mlx, fdf->win, WINDOW_X - MENU - 100,
				WINDOW_Y - MENU - 30, 16711935, "Map: ");
		mlx_string_put(fdf->mlx, fdf->win, WINDOW_X - MENU - 100,
				WINDOW_Y - MENU - 10, 16711935, fdf->argv);
	}
	mlx_string_put(fdf->mlx, fdf->win, WINDOW_X - MENU - 100,
			WINDOW_Y - MENU + 30, 16711935, "Shift++ - menu++");
	mlx_string_put(fdf->mlx, fdf->win, WINDOW_X - MENU - 100,
			WINDOW_Y - MENU + 50, 16711935, "Space++ - projection++");
	mlx_string_put(fdf->mlx, fdf->win, WINDOW_X - MENU - 100,
			WINDOW_Y - MENU + 70, 16711935, "Enter - 3 colors");
	mlx_string_put(fdf->mlx, fdf->win, WINDOW_X - MENU - 100,
			WINDOW_Y - MENU + 90, 16711935, "< > K L O P - move");
	mlx_string_put(fdf->mlx, fdf->win, WINDOW_X - MENU - 100,
			WINDOW_Y - MENU + 110, 16711935, "Del - initial setup");
}

void			image_creation(t_fdf *fdf)
{
	backgraund(fdf);
	line_drawing(fdf, 0, 0);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image, 0, 0);
	if (fdf->switcher == 2)
		menu_1(fdf);
	if (fdf->switcher == 1)
	{
		palitra(fdf, 0, 0);
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image_2, 0, 0);
	}
	image_menu(fdf);
}

static void		init_images(t_fdf *fdf)
{
	fdf->image = mlx_new_image(fdf->mlx, WINDOW_X, WINDOW_Y);
	fdf->image_menu = mlx_new_image(fdf->mlx, MENU, MENU);
	fdf->image_mode_menu = mlx_new_image(fdf->mlx, MENU, MENU);
	fdf->image_col_menu = mlx_new_image(fdf->mlx, MENU, MENU);
	fdf->data_img = (int *)mlx_get_data_addr(fdf->image,
			&fdf->bpp, &fdf->size_line, &fdf->endian);
	fdf->data_img_menu = (int *)mlx_get_data_addr(fdf->image_menu,
			&fdf->bpp, &fdf->size_line, &fdf->endian);
	fdf->data_img_mode_menu = (int *)mlx_get_data_addr(fdf->image_mode_menu,
			&fdf->bpp, &fdf->size_line, &fdf->endian);
	fdf->data_img_col_menu = (int *)mlx_get_data_addr(fdf->image_col_menu,
			&fdf->bpp, &fdf->size_line, &fdf->endian);
	fdf->image_2 = mlx_new_image(fdf->mlx, 100, 100);
	fdf->data_img_2 = (int *)mlx_get_data_addr(fdf->image_2,
			&fdf->bpp, &fdf->size_line, &fdf->endian);
}

void			initialization(t_fdf *fdf, char *argv)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WINDOW_X, WINDOW_Y, "FDF");
	init_images(fdf);
	fdf->projection = 1;
	fdf->colors[0] = 16776656;
	fdf->colors[1] = 16777200;
	fdf->colors[2] = 14695473;
	fdf->colors[3] = 1677200;
	fdf->colors[4] = 14695473;
	fdf->backgraund = 0;
	fdf->switcher = 0;
	fdf->brush = 255;
	fdf->type_of_brush = 1;
	fdf->type_of_coloration = 0;
	fdf->mouse_mode = 1;
	fdf->argv = argv;
	save_color(fdf->karta, fdf->width_p, fdf->height_p);
	required_values(fdf, WINDOW_X * 80 / 100, WINDOW_Y * 80 / 100);
	image_creation(fdf);
	program_control(fdf);
	mlx_loop(fdf->mlx);
}
