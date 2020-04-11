
#include "../includes/fdf.h"

void		x_rotate(int *y, int *z, double angle)
{
	double y_help;
	double z_help;

	y_help = (double)*y;
	z_help = (double)*z;
	*y = (int)(y_help * cos(angle) + z_help * sin(angle));
	*z = (int)(-y_help * sin(angle) + z_help * cos(angle));
}

void		y_rotate(int *x, int *z, double angle)
{
	double x_help;
	double z_help;

	x_help = (double)*x;
	z_help = (double)*z;
	*x = (int)(x_help * cos(angle) + z_help * sin(angle));
	*z = (int)(-x_help * sin(angle) + z_help * cos(angle));
}

void		z_rotate(int *x, int *y, double angle)
{
	double x_help;
	double y_help;

	x_help = (double)*x;
	y_help = (double)*y;
	*x = (int)(x_help * cos(angle) - y_help * sin(angle));
	*y = (int)(x_help * sin(angle) + y_help * cos(angle));
}

void		iso_projection(int *x, int *y, int z)
{
	double x_help;
	double y_help;

	x_help = (double)*x;
	y_help = (double)*y;
	*x = (int)((x_help - y_help) * cos(0.523599));
	*y = -z + (int)((x_help + y_help) * sin(0.523599));
}
