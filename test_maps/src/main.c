/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeckard <hdeckard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:33:18 by hdeckard          #+#    #+#             */
/*   Updated: 2020/02/18 16:47:26 by hdeckard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	remove_fdf(t_fdf *fdf)
{
	if (fdf->karta != NULL)
		remove_map(&fdf->karta, fdf->width_p, fdf->height_p);
	free(fdf);
}

int		main(int argc, char **argv)
{
	t_fdf		*fdf;

	if (argc == 2)
	{
		if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
			return (0);
		fdf->width_p = 0;
		fdf->height_p = 0;
		if (read_check(argv[1], fdf) == -1 || ft_new_t_p(fdf) == -1
		|| fill_t_p_karta(argv[1], fdf) == -1)
		{
			remove_fdf(fdf);
			ft_printf("Invalid map\n");
			return (0);
		}
		initialization(fdf, argv[1]);
	}
	else
		ft_printf("I need a map\n");
	return (0);
}
