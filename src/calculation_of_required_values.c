
#include "../includes/fdf.h"

void	get_first_point(t_fdf *fdf)
{
	int vector_x;
	int vector_y;
	int z;

	vector_x = (int)((double)(fdf->width_p - 1) *
			((double)fdf->step * fdf->mn_x / 2));
	vector_y = (int)((double)(fdf->height_p - 1) *
			((double)fdf->step * fdf->mn_y / 2));
	z = fdf->karta[0][0]->z * (int)((double)fdf->step * fdf->mn);
	x_rotate(&vector_y, &z, fdf->rad_p);
	y_rotate(&vector_x, &z, fdf->rad_p_2);
	z_rotate(&vector_x, &vector_y, fdf->rad_p_3);
	if (fdf->projection == 1)
		iso_projection(&vector_x, &vector_y, z);
	fdf->first_x = fdf->center_x - vector_x;
	fdf->first_y = fdf->center_y - vector_y;
}

void	required_values(t_fdf *fdf, int fw, int fh)
{
	int field_x;
	int field_y;

	fdf->center_x = WINDOW_X / 2;
	fdf->center_y = WINDOW_Y / 2;
	field_x = (int)((double)(fdf->width_p + fdf->height_p) * fabs(cos(RAD)));
	if (field_x == 0)
		field_x = 1;
	field_y = (int)(((double)(fdf->width_p +
			fdf->height_p)) * fabs(sin(RAD))
					+ fdf->max_z - fdf->min_z);
	if (field_y == 0)
		field_y = 1;
	fdf->step = fw / field_x;
	if (fh / field_y < fdf->step)
		fdf->step = fh / field_y;
	fdf->mn = 1;
	fdf->mn_x = 1;
	fdf->mn_y = 1;
	fdf->rad_p = 0;
	fdf->rad_p_2 = 0;
	fdf->rad_p_3 = 0;
	fdf->backgraund = 0;
}
