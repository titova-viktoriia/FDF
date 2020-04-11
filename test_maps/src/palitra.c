/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeckard <hdeckard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:33:25 by hdeckard          #+#    #+#             */
/*   Updated: 2020/02/05 17:36:27 by hdeckard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			picture(t_fdf *fdf)
{
	int i;

	if (fdf->type_of_brush == 1)
	{
		i = 24;
		while (i <= 27)
		{
			fdf->data_img_2[i * 100 + 24] = fdf->brush;
			fdf->data_img_2[i * 100 + 25] = fdf->brush;
			fdf->data_img_2[i * 100 + 26] = fdf->brush;
			fdf->data_img_2[i * 100 + 27] = fdf->brush;
			i++;
		}
	}
	if (fdf->type_of_brush == 2 || fdf->type_of_brush == 3)
	{
		i = 10;
		while (i <= 40)
		{
			fdf->data_img_2[i * 100 + 25] = fdf->brush;
			fdf->data_img_2[i * 100 + 26] = fdf->brush;
			i++;
		}
	}
}

void			palitra(t_fdf *fdf, int x, int y)
{
	int i;

	while (y < 100)
	{
		x = 0;
		while (x < 100)
		{
			i = y * 100 + x;
			if (x < 50 && y < 50)
				fdf->data_img_2[i] = fdf->backgraund_color;
			if (x >= 50 && y < 50)
				fdf->data_img_2[i] = 12399524;
			if (x < 50 && y >= 50)
				fdf->data_img_2[i] = 255;
			if (x >= 50 && y >= 50)
				fdf->data_img_2[i] = 25500;
			x++;
		}
		y++;
	}
	picture(fdf);
}
