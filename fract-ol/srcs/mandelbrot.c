#include "fractol.h"

void	make_mandelbrot(t_info *info, t_cnb z, t_cnb c)
{
	float norm,tmp;

	norm = z.Re * z.Re + z.Im * z.Im;
	tmp = 0;
	while (++(info->depth) < info->max && norm < 4.0)
	{
		tmp = z.Re;
		z.Re = z.Re * z.Re - z.Im * z.Im + c.Re;
		z.Im = 2.0 * z.Im * tmp + c.Im;
		norm = z.Re * z.Re + z.Im * z.Im;
	}
}
