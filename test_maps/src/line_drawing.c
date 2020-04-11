/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeckard <hdeckard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:31:37 by hdeckard          #+#    #+#             */
/*   Updated: 2020/02/12 15:58:11 by hdeckard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				fill_or_not_to_fill(t_fdf *fdf, int x, int y, int i)
{
	if (x < 0 || y < 0 || x >= WINDOW_X || y >= WINDOW_Y)
		return (0);
	else if (fdf->projection != 1 && fdf->data_img[i] != fdf->backgraund_color)
	{
		if (sin(fdf->rad_p) < 0 && cos(fdf->rad_p >= 0)
		&& sin(fdf->rad_p_2) >= 0 && cos(fdf->rad_p_2) <= 0)
			return (0);
		if (sin(fdf->rad_p) < 0 && cos(fdf->rad_p >= 0)
		&& sin(fdf->rad_p_2) <= 0 && cos(fdf->rad_p_2) <= 0)
			return (0);
		if (sin(fdf->rad_p) == 0 && sin(fdf->rad_p_2) >= 0)
			return (0);
		if (sin(fdf->rad_p_2) == 0 && sin(fdf->rad_p) >= 0)
			return (0);
		if (sin(fdf->rad_p) > 0 && cos(fdf->rad_p >= 0)
		&& sin(fdf->rad_p_2) >= 0 && cos(fdf->rad_p_2) >= 0)
			return (0);
		if (sin(fdf->rad_p) > 0 && cos(fdf->rad_p >= 0)
		&& sin(fdf->rad_p_2) <= 0 && cos(fdf->rad_p_2) >= 0)
			return (0);
	}
	return (1);
}

static void		alg_y(t_fdf *fdf, int c1, int c2, int i)
{
	int error;
	int x;
	int y;

	error = fdf->deltay / 2;
	x = fdf->x0;
	y = fdf->y0;
	if (fill_or_not_to_fill(fdf, x, y, WINDOW_X * y + x) == 1)
		fdf->data_img[WINDOW_X * y + x] =
				color(c1, c2, fdf->deltay + 1, abs(y - fdf->y0));
	while (i < fdf->deltay - 1)
	{
		error = error - fdf->deltax;
		if (error < 0)
		{
			error = error + fdf->deltay;
			x = x + fdf->dirx;
		}
		y = y + fdf->diry;
		i++;
		if (fill_or_not_to_fill(fdf, x, y, WINDOW_X * y + x) == 1)
			fdf->data_img[WINDOW_X * y + x] =
					color(c1, c2, fdf->deltay + 1, abs(y - fdf->y0));
	}
}

static void		alg_x(t_fdf *fdf, int c1, int c2, int i)
{
	int error;
	int x;
	int y;

	error = fdf->deltax / 2;
	x = fdf->x0;
	y = fdf->y0;
	if (fill_or_not_to_fill(fdf, x, y, WINDOW_X * y + x) == 1)
		fdf->data_img[WINDOW_X * y + x] =
				color(c1, c2, fdf->deltax + 1, abs(x - fdf->x0));
	while (i < fdf->deltax - 1)
	{
		error = error - fdf->deltay;
		if (error < 0)
		{
			error = error + fdf->deltax;
			y = y + fdf->diry;
		}
		x = x + fdf->dirx;
		i++;
		if (fill_or_not_to_fill(fdf, x, y, WINDOW_X * y + x) == 1)
			fdf->data_img[WINDOW_X * y + x] =
					color(c1, c2, fdf->deltax + 1, abs(x - fdf->x0));
	}
}

void			line(t_fdf *fdf, int c1, int c2)
{
	fdf->deltax = abs(fdf->x1 - fdf->x0);
	fdf->deltay = abs(fdf->y1 - fdf->y0);
	fdf->diry = fdf->y1 - fdf->y0;
	if (fdf->diry > 0)
		fdf->diry = 1;
	if (fdf->diry < 0)
		fdf->diry = -1;
	fdf->dirx = fdf->x1 - fdf->x0;
	if (fdf->dirx > 0)
		fdf->dirx = 1;
	if (fdf->dirx < 0)
		fdf->dirx = -1;
	if (fdf->deltay > fdf->deltax)
		alg_y(fdf, c1, c2, 0);
	else
		alg_x(fdf, c1, c2, 0);
}

void			line_drawing(t_fdf *fdf, int x, int y)
{
	while (y < fdf->height_p)
	{
		get_ab(fdf, x, y, 1);
		while (x < fdf->width_p)
		{
			if (y < fdf->height_p - 1)
			{
				get_ab(fdf, x, y + 1, 2);
				line(fdf, fdf->karta[y][x]->color, fdf->karta[y + 1][x]->color);
			}
			if (x < fdf->width_p - 1)
			{
				get_ab(fdf, x + 1, y, 2);
				line(fdf, fdf->karta[y][x]->color, fdf->karta[y][x + 1]->color);
				fdf->x0 = fdf->x1;
				fdf->y0 = fdf->y1;
			}
			x++;
		}
		y++;
		x = 0;
	}
	last_point(fdf);
}
