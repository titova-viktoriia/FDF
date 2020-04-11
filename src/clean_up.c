
#include "../includes/fdf.h"

void			remove_map(t_point ****karta, int x1, int y1)
{
	t_point		***help;
	int			y;
	int			x;

	y = 0;
	x = 0;
	help = *karta;
	while (y < y1)
	{
		while (x < x1)
		{
			free(help[y][x]);
			help[y][x] = NULL;
			x++;
		}
		free(help[y]);
		help[y] = NULL;
		x = 0;
		y++;
	}
	free(help);
	help = NULL;
}

void			clean_up(t_fdf *fdf)
{
	remove_map(&fdf->karta, fdf->width_p, fdf->height_p);
	mlx_destroy_image(fdf->mlx, fdf->image);
	mlx_destroy_image(fdf->mlx, fdf->image_2);
	mlx_destroy_image(fdf->mlx, fdf->image_menu);
	mlx_destroy_image(fdf->mlx, fdf->image_mode_menu);
	mlx_destroy_window(fdf->mlx, fdf->win);
}
