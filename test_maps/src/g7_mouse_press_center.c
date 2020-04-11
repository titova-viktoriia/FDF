/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeckard <hdeckard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:33:25 by hdeckard          #+#    #+#             */
/*   Updated: 2020/02/18 15:31:02 by hdeckard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			mouse_press_center(int button, int x, int y, t_fdf *fdf)
{
	if (x > MENU && y > MENU && button == LEFT_BUTTON_MOUSE)
	{
		fdf->fix_x = x;
		fdf->fix_y = y;
		fdf->mouse = 1;
	}
}

void			mouse_move_center(int x, int y, t_fdf *fdf)
{
	if (fdf->mouse == 1)
	{
		fdf->center_x = fdf->center_x + (x - fdf->fix_x);
		fdf->center_y = fdf->center_y + (y - fdf->fix_y);
		fdf->fix_x = x;
		fdf->fix_y = y;
	}
	image_creation(fdf);
}

void			mouse_press_mode(int button, int x, int y, t_fdf *fdf)
{
	if (x > WINDOW_X - MENU && y > 50 && y < 100)
		if (button == LEFT_BUTTON_MOUSE)
			fdf->mouse_mode = 1;
	if (x > WINDOW_X - MENU && y > 100 && y < 150)
		if (button == LEFT_BUTTON_MOUSE)
			fdf->mouse_mode = 2;
}

void			mouse_press_color(int button, int x, int y, t_fdf *fdf)
{
	int y1;

	y1 = y - (WINDOW_Y - MENU + 50);
	if (x < MENU && y > WINDOW_Y - MENU)
	{
		if (button == LEFT_BUTTON_MOUSE)
			fdf->mouse_color_1 = fdf->data_img_col_menu[MENU * y1 + x];
		if (button == RIGHT_BUTTON_MOUSE)
			fdf->mouse_color_2 = fdf->data_img_col_menu[MENU * y1 + x];
		set_color_mouse(fdf, fdf->mouse_color_1, fdf->mouse_color_2);
		image_creation(fdf);
	}
}

void			mouse_scroll(int button, t_fdf *fdf)
{
	if (fdf->mouse_mode == 1)
	{
		if (button == 4)
			fdf->step = fdf->step + 10;
		if (button == 5)
		{
			if (fdf->step > 10)
				fdf->step = fdf->step - 10;
		}
	}
	if (fdf->mouse_mode == 2)
	{
		if (button == 4)
			fdf->mn = fdf->mn + 0.1;
		if (button == 5 && fdf->mn >= 0.1)
			fdf->mn = fdf->mn - 0.1;
	}
	image_creation(fdf);
}
