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

int			key_press(int button, t_fdf *fdf)
{
	if (button <= 14)
		key_press_2(button, fdf);
	if (button == SPACE_BUTTON || button == DELETE_BUTTON
	|| button == ESC_EXIT || button == TAB_BUTTON)
		key_press_3(button, fdf);
	if ((button >= 123 && button <= 126) ||
	button == CTRL_BUTTON || button == SHIFT_BUTTON)
		key_press_4(button, fdf);
	if (button == COMMAND_BUTTON || button == ENTER_BUTTON)
		key_press_5(button, fdf);
	if (button == L_BUTTON || button == K_BUTTON || button == LESS_BUTTON
	|| button == GREATER_BUTTON || button == O_BUTTON || button == P_BUTTON)
		key_press_6(button, fdf);
	if (button == MINUS_BUTTON || button == PLUS_BUTTON || button == SHIFT_LEFT)
		key_press_7(button, fdf);
	image_creation(fdf);
	return (0);
}

int			mouse_press(int button, int x_event, int x_mask, void *data)
{
	t_fdf *fdf;

	fdf = data;
	if (fdf->switcher == 1)
		mouse_press_palitra(button, x_event, x_mask, fdf);
	else
	{
		mouse_press_center(button, x_event, x_mask, fdf);
		mouse_press_rotate(button, x_event, x_mask, fdf);
		mouse_scroll(button, fdf);
	}
	if (fdf->switcher == 2)
	{
		mouse_press_background(button, x_event, x_mask, fdf);
		mouse_press_mode(button, x_event, x_mask, fdf);
		mouse_press_color(button, x_event, x_mask, fdf);
	}
	return (0);
}

int			mouse_move(int x, int y, void *data)
{
	t_fdf *fdf;

	fdf = data;
	if (fdf->switcher == 1)
		mouse_move_palitra(x, y, fdf);
	else
	{
		mouse_move_center(x, y, fdf);
		mouse_move_rotate(x, y, fdf);
	}
	return (0);
}

int			mouse_nopress(int button, int x, int y, void *data)
{
	t_fdf *fdf;

	fdf = data;
	if (button > -1 && fdf->switcher == 1
	&& fdf->type_of_brush == 3 && fdf->mouse == 1)
		mouse_nopress_palitra(x, y, fdf);
	fdf->mouse = 0;
	return (0);
}

void		program_control(t_fdf *fdf)
{
	mlx_hook(fdf->win, 4, 0, mouse_press, fdf);
	mlx_hook(fdf->win, 6, 0, mouse_move, fdf);
	mlx_hook(fdf->win, 5, 0, mouse_nopress, fdf);
	mlx_hook(fdf->win, 2, 0, key_press, fdf);
}
