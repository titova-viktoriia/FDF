
#include "../includes/fdf.h"

void			mouse_press_rotate(int button, int x, int y, t_fdf *fdf)
{
	if (x > MENU && y > MENU)
	{
		if (button == RIGHT_BUTTON_MOUSE)
		{
			fdf->fix_x = x;
			fdf->fix_y = y;
			fdf->mouse = 3;
		}
	}
}

void			mouse_move_rotate(int x, int y, t_fdf *fdf)
{
	if (fdf->mouse == 3)
	{
		if (x > fdf->fix_x)
			fdf->rad_p_3 = fdf->rad_p_3 - 0.03;
		if (x < fdf->fix_x)
			fdf->rad_p_3 = fdf->rad_p_3 + 0.03;
		if (y < fdf->fix_y)
			fdf->rad_p_2 = fdf->rad_p_2 + 0.03;
		if (y > fdf->fix_y)
			fdf->rad_p_2 = fdf->rad_p_2 - 0.03;
	}
	fdf->fix_x = x;
	fdf->fix_y = y;
	image_creation(fdf);
}
