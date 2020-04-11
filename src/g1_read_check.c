
#include "../includes/fdf.h"

int		read_check(char *argv, t_fdf *fdf)
{
	int		point_count;
	char	*line;
	int		fd;
	int		gnl;

	point_count = 0;
	fd = open(argv, O_RDONLY);
	while ((gnl = get_next_line(fd, &line)) == 1)
	{
		if (fdf->width_p == 0)
			fdf->width_p = ft_w_count(line, ' ');
		else
			point_count = ft_w_count(line, ' ');
		if (fdf->height_p != 0 && point_count != fdf->width_p)
			return (-1);
		fdf->height_p++;
		free(line);
	}
	close(fd);
	if (gnl == -1)
		return (-1);
	return (0);
}
