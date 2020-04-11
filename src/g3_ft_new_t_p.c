
#include "../includes/fdf.h"

int	ft_new_t_p(t_fdf *fdf)
{
	int i;
	int x;

	if (!(fdf->karta = (t_point ***)malloc(sizeof(t_point **) * fdf->height_p)))
		return (-1);
	i = 0;
	while (i < fdf->height_p)
	{
		if (!(fdf->karta[i] = (t_point **)malloc(sizeof(t_point *)
				* fdf->width_p)))
			return (-1);
		x = 0;
		while (x < fdf->width_p)
		{
			if (!(fdf->karta[i][x] = (t_point *)malloc(sizeof(t_point))))
				return (-1);
			x++;
		}
		i++;
	}
	return (0);
}
