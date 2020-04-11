/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeckard <hdeckard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:33:06 by hdeckard          #+#    #+#             */
/*   Updated: 2020/02/12 18:15:34 by hdeckard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	last_point(t_fdf *fdf)
{
	if (fill_or_not_to_fill(fdf, fdf->x1, fdf->y1,
			WINDOW_X * fdf->y1 + fdf->x1) == 1)
		fdf->data_img[WINDOW_X * fdf->y1 + fdf->x1] =
				color(fdf->karta[fdf->height_p - 1]
				[fdf->width_p - 1]->color,
						fdf->karta[fdf->height_p - 1]
						[fdf->width_p - 1]->color, 4, 2);
}

void	get_ab(t_fdf *fdf, int x, int y, int i)
{
	int z;

	if (x == 0 && y == 0)
		get_first_point(fdf);
	fdf->x1 = x * (int)((double)fdf->step * fdf->mn_x);
	fdf->y1 = y * (int)((double)fdf->step * fdf->mn_y);
	z = fdf->karta[y][x]->z * (int)((double)fdf->step * fdf->mn);
	x_rotate(&fdf->y1, &z, fdf->rad_p);
	y_rotate(&fdf->x1, &z, fdf->rad_p_2);
	z_rotate(&fdf->x1, &fdf->y1, fdf->rad_p_3);
	if (fdf->projection == 1)
		iso_projection(&fdf->x1, &fdf->y1, z);
	fdf->x1 = fdf->first_x + fdf->x1;
	fdf->y1 = fdf->first_y + fdf->y1;
	if (i == 1)
	{
		fdf->x0 = fdf->x1;
		fdf->y0 = fdf->y1;
	}
}
