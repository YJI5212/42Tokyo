#include "fractol.h"

void	make_mandelbrot(t_info *info, t_cnb z, t_cnb c)
{
	double norm,tmp;

	norm = pow((double)z.Re, 2.0) + pow((double)z.Im, 2.0);
	tmp = 0.0;
	info->depth = -1;
	while (++(info->depth) < info->max && norm < 4.0)
	{
		tmp = z.Re;
		z.Re = pow((double)z.Re, 2.0) - pow((double)z.Im, 2.0) + c.Re;
		z.Im = 2.0 * z.Im * tmp + c.Im;
		norm = pow((double)z.Re, 2.0) + pow((double)z.Im, 2.0);
	}
}
