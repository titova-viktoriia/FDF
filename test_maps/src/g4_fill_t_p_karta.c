/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g4_fill_t_p_karta.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeckard <hdeckard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:32:49 by hdeckard          #+#    #+#             */
/*   Updated: 2020/02/18 17:48:02 by hdeckard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	is_correct_d(char *tmp_line)
{
	if (tmp_line[0] == '-')
		tmp_line++;
	while (tmp_line[0] != ' ' && tmp_line[0] != ',' && tmp_line[0] != '\0')
	{
		if (ft_isdigit(tmp_line[0]) == 1)
			tmp_line++;
		else
			return (-1);
	}
	if (tmp_line[0] == '\0')
		return (0);
	if (ft_isdigit(tmp_line[0]) != 1
	&& (tmp_line[0] != ' ' && tmp_line[0] != ','))
		return (-1);
	return (0);
}

static int	fill_z(t_fdf *fdf, int x, int y, char *tmp_line)
{
	if (is_correct_d(tmp_line) == 0)
		fdf->karta[y][x]->z = ft_atoi(tmp_line);
	else
		return (0);
	if (x == 0 && y == 0)
	{
		fdf->max_z = fdf->karta[y][x]->z;
		fdf->min_z = fdf->karta[y][x]->z;
	}
	else
	{
		if (fdf->karta[y][x]->z > fdf->max_z)
			fdf->max_z = fdf->karta[y][x]->z;
		if (fdf->karta[y][x]->z < fdf->min_z)
			fdf->min_z = fdf->karta[y][x]->z;
	}
	return (1);
}

static int	fill_color(t_fdf *fdf, int x, int y, char *tmp_line)
{
	char	*line;

	fdf->karta[y][x]->color = 16119285;
	if ((((tmp_line)[0] != '0' && (tmp_line + 1)[0] != 'x')
	|| (tmp_line + 2)[0] == '\0'))
		return (0);
	line = tmp_line + 2;
	while (line[0] != ' ' && line[0] != '\0')
	{
		if (ft_isdigit(line[0]) == 1 ||
			(line[0] >= 'a' && line[0] <= 'f')
			|| (line[0] >= 'A' && line[0] <= 'F'))
			line++;
		else
			return (0);
	}
	if (line[0] != ' ' && line[0] != '\0')
		return (0);
	fdf->karta[y][x]->color = ft_atoi_16_10(tmp_line);
	return (1);
}

static int	zapolnyaem(char *tmp_line, t_fdf *fdf, int x, int y)
{
	while (tmp_line && x < fdf->width_p - 1)
	{
		while (tmp_line[0] == ' ')
			tmp_line++;
		x++;
		if (!(fill_z(fdf, x, y, tmp_line)))
			return (0);
		while (ft_isdigit(tmp_line[0]) == 1)
			tmp_line++;
		if (tmp_line[0] == ',')
		{
			if (!(fill_color(fdf, x, y, tmp_line + 1)))
				return (0);
			while (tmp_line[0] != ' ' && tmp_line[0] != '\0')
				tmp_line++;
		}
		else
			fdf->karta[y][x]->color = 16777215;
	}
	return (1);
}

int			fill_t_p_karta(char *argv, t_fdf *fdf)
{
	int		x;
	int		y;
	char	*line;
	int		fd;

	y = 0;
	fd = open(argv, O_RDONLY);
	while ((get_next_line(fd, &line)) == 1)
	{
		x = -1;
		if (!zapolnyaem(line, fdf, x, y))
			return (-1);
		y++;
		free(line);
	}
	close(fd);
	return (0);
}
