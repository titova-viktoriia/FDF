/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_of_coloration.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeckard <hdeckard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:33:38 by hdeckard          #+#    #+#             */
/*   Updated: 2020/02/18 15:31:02 by hdeckard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			set_color_mouse(t_fdf *fdf, int c1, int c2)
{
	int x;
	int y;
	int now;
	int delta;

	x = 0;
	y = 0;
	delta = (fdf->max_z - fdf->min_z);
	while (y < fdf->height_p)
	{
		while (x < fdf->width_p)
		{
			now = fdf->karta[y][x]->z - fdf->min_z;
			fdf->karta[y][x]->color = color(c1, c2, delta, now);
			x++;
		}
		y++;
		x = 0;
	}
}

void			set_color_g(t_fdf *fdf)
{
	int x;
	int y;
	int now;
	int delta;

	x = 0;
	y = 0;
	delta = (fdf->max_z - fdf->min_z);
	while (y < fdf->height_p)
	{
		while (x < fdf->width_p)
		{
			now = fdf->karta[y][x]->z - fdf->min_z;
			fdf->karta[y][x]->color = color(COLOR_1, COLOR_2, delta, now);
			x++;
		}
		y++;
		x = 0;
	}
}

void			set_color_z(t_fdf *fdf)
{
	int x;
	int y;
	int i;
	int shag;

	y = 0;
	shag = (fdf->max_z - fdf->min_z) / 5;
	if (shag == 0)
		shag = 1;
	while (y < fdf->height_p)
	{
		x = 0;
		while (x < fdf->width_p)
		{
			i = fdf->karta[y][x]->z / shag;
			fdf->karta[y][x]->color = fdf->colors[i];
			x++;
		}
		y++;
	}
}

void			return_true_color(t_point ***karta, int w, int h)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < h)
	{
		while (x < w)
		{
			karta[y][x]->color = karta[y][x]->store;
			x++;
		}
		y++;
		x = 0;
	}
}

void			save_color(t_point ***karta, int w, int h)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < h)
	{
		while (x < w)
		{
			karta[y][x]->store = karta[y][x]->color;
			x++;
		}
		y++;
		x = 0;
	}
}
