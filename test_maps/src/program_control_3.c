/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeckard <hdeckard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:33:25 by hdeckard          #+#    #+#             */
/*   Updated: 2020/02/18 17:37:54 by hdeckard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		key_press_2(int button, t_fdf *fdf)
{
	if (button == A_BUTTON)
		fdf->mn_y = fdf->mn_y + 0.1;
	if (button == S_BUTTON && fdf->mn_y >= 0.1)
		fdf->mn_y = fdf->mn_y - 0.1;
	if (button == D_BUTTON)
		fdf->mn_y = 1;
	if (button == Z_BUTTON)
		fdf->mn_x = fdf->mn_x + 0.1;
	if (button == X_BUTTON && fdf->mn_x >= 0.1)
		fdf->mn_x = fdf->mn_x - 0.1;
	if (button == C_BUTTON)
		fdf->mn_x = 1;
	if (button == Q_BUTTON)
		fdf->mn = fdf->mn + 0.1;
	if (button == W_BUTTON && fdf->mn >= 0.1)
		fdf->mn = fdf->mn - 0.1;
	if (button == E_BUTTON)
		fdf->mn = 1;
}

void		fdf_rad_return(t_fdf *fdf)
{
	fdf->rad_p = 0;
	fdf->rad_p_2 = 0;
	fdf->rad_p_3 = 0;
}

void		initial_setup(t_fdf *fdf)
{
	required_values(fdf, 1300 * 80 / 100, 1300 * 80 / 100);
	return_true_color(fdf->karta, fdf->width_p, fdf->height_p);
	fdf->mouse_color_1 = 0;
	fdf->mouse_color_2 = 0;
	fdf->mouse_mode = 1;
}
