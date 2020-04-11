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

void				mouse_press_background(int button, int x, int y, t_fdf *fdf)
{
	if (button == LEFT_BUTTON_MOUSE)
	{
		if (x <= MENU && y <= MENU)
		{
			fdf->backgraund_color = fdf->data_img_menu[MENU * y + x];
			fdf->backgraund = 5;
		}
	}
	image_creation(fdf);
}

void				mouse_left_button(int x, int y, t_fdf *fdf)
{
	if (fdf->type_of_brush == 2)
	{
		fdf->type_of_brush = 3;
		fdf->x0 = x;
		fdf->y0 = y;
		fdf->mouse = 1;
	}
	if (x <= 50 && y <= 50)
	{
		if (fdf->type_of_brush == 1)
			fdf->type_of_brush = 2;
		else if (fdf->type_of_brush == 3)
			fdf->type_of_brush = 1;
	}
	else if (x <= 100 && y <= 100)
		fdf->brush = fdf->data_img_2[100 * y + x];
	else if (fdf->type_of_brush == 1)
	{
		fdf->mouse = 1;
		fdf->data_img[WINDOW_X * y + x] = fdf->brush;
		fdf->data_img[WINDOW_X * y + x + 1] = fdf->brush;
		fdf->data_img[WINDOW_X * (y + 1) + x] = fdf->brush;
		fdf->data_img[WINDOW_X * (y + 1) + x + 1] = fdf->brush;
	}
}

void				mouse_press_palitra(int button, int x, int y, t_fdf *fdf)
{
	if (button == LEFT_BUTTON_MOUSE)
		mouse_left_button(x, y, fdf);
	if (button == RIGHT_BUTTON_MOUSE)
	{
		fdf->mouse = 2;
		fdf->data_img[WINDOW_X * y + x] = fdf->backgraund_color;
		fdf->data_img[WINDOW_X * y + x + 1] = fdf->backgraund_color;
		fdf->data_img[WINDOW_X * (y + 1) + x] = fdf->backgraund_color;
		fdf->data_img[WINDOW_X * (y + 1) + x + 1] = fdf->backgraund_color;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image, 0, 0);
	palitra(fdf, 0, 0);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image_2, 0, 0);
	image_menu(fdf);
}

void				mouse_move_palitra(int x, int y, t_fdf *fdf)
{
	if (fdf->mouse == 1 && fdf->type_of_brush == 1)
	{
		fdf->data_img[WINDOW_X * y + x] = fdf->brush;
		fdf->data_img[WINDOW_X * y + x + 1] = fdf->brush;
		fdf->data_img[WINDOW_X * (y + 1) + x] = fdf->brush;
		fdf->data_img[WINDOW_X * (y + 1) + x + 1] = fdf->brush;
	}
	if (fdf->mouse == 2)
	{
		fdf->data_img[WINDOW_X * y + x] = fdf->backgraund_color;
		fdf->data_img[WINDOW_X * y + x + 1] = fdf->backgraund_color;
		fdf->data_img[WINDOW_X * (y + 1) + x] = fdf->backgraund_color;
		fdf->data_img[WINDOW_X * (y + 1) + x + 1] = fdf->backgraund_color;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image, 0, 0);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image_2, 0, 0);
	image_menu(fdf);
}

void				mouse_nopress_palitra(int x, int y, t_fdf *fdf)
{
	fdf->x1 = x;
	fdf->y1 = y;
	line(fdf, fdf->brush, fdf->brush);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image, 0, 0);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image_2, 0, 0);
	image_menu(fdf);
	fdf->type_of_brush = 2;
}
