/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeckard <hdeckard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:33:25 by hdeckard          #+#    #+#             */
/*   Updated: 2020/02/18 17:48:02 by hdeckard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		key_press_7(int button, t_fdf *fdf)
{
	if (button == PLUS_BUTTON)
		fdf->step = fdf->step + 10;
	if (button == MINUS_BUTTON)
	{
		if (fdf->step > 10)
			fdf->step = fdf->step - 10;
	}
	if (button == SHIFT_LEFT)
	{
		if (fdf->switcher < 2)
			fdf->switcher++;
		else
			fdf->switcher = 0;
	}
}

void		key_press_6(int button, t_fdf *fdf)
{
	if (button == LESS_BUTTON)
		fdf->rad_p = fdf->rad_p - 0.05;
	if (button == GREATER_BUTTON)
		fdf->rad_p = fdf->rad_p + 0.05;
	if (button == K_BUTTON)
		fdf->rad_p_2 = fdf->rad_p_2 - 0.05;
	if (button == L_BUTTON)
		fdf->rad_p_2 = fdf->rad_p_2 + 0.05;
	if (button == O_BUTTON)
		fdf->rad_p_3 = fdf->rad_p_3 - 0.05;
	if (button == P_BUTTON)
		fdf->rad_p_3 = fdf->rad_p_3 + 0.05;
}

void		key_press_5(int button, t_fdf *fdf)
{
	if (button == ENTER_BUTTON)
	{
		fdf->type_of_coloration++;
		if (fdf->type_of_coloration == 0)
			return_true_color(fdf->karta, fdf->width_p, fdf->height_p);
		if (fdf->type_of_coloration == 1)
			set_color_g(fdf);
		if (fdf->type_of_coloration == 2)
		{
			set_color_z(fdf);
			fdf->type_of_coloration = -1;
		}
	}
	if (button == COMMAND_BUTTON)
	{
		fdf->rad_p = 0;
		fdf->rad_p_2 = 0;
		fdf->rad_p_3 = 0;
	}
}

void		key_press_4(int button, t_fdf *fdf)
{
	if (button == LEFT_ARROW)
		fdf->center_x = fdf->center_x - 10;
	if (button == RIGHT_ARROW)
		fdf->center_x = fdf->center_x + 10;
	if (button == UP_ARROW)
		fdf->center_y = fdf->center_y - 10;
	if (button == ARROW_TO_DOWN)
		fdf->center_y = fdf->center_y + 10;
	if (button == CTRL_BUTTON)
	{
		fdf->center_x = WINDOW_X / 2;
		fdf->center_y = WINDOW_Y / 2;
	}
	if (button == SHIFT_BUTTON)
	{
		if (fdf->projection == 1)
			ft_printf("\nProjection Type: Isometric\n");
		else
			ft_printf("\nProjection Type: Parallel\n");
		ft_printf("The x-axis rotation angle is %f\n", fdf->rad_p);
		ft_printf("The y-axis rotation angle is %f\n", fdf->rad_p_2);
		ft_printf("The z-axis rotation angle is %f\n", fdf->rad_p_3);
	}
}

void		key_press_3(int button, t_fdf *fdf)
{
	if (button == SPACE_BUTTON)
	{
		if (fdf->projection == 1)
		{
			fdf_rad_return(fdf);
			fdf->projection = 2;
		}
		else if (fdf->projection == 2)
			fdf->projection = 1;
	}
	if (button == DELETE_BUTTON)
		initial_setup(fdf);
	if (button == ESC_EXIT)
	{
		clean_up(fdf);
		free(fdf);
		exit(0);
	}
	if (button == TAB_BUTTON)
	{
		if (fdf->backgraund < 5)
			fdf->backgraund++;
		else
			fdf->backgraund = 0;
	}
}
