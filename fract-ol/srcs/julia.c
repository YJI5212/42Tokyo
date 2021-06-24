#include "fractol.h"

void	set_julia_c(t_info *info)
{
	/* info->julia_c = (t_cnb) {.Re = -0.506667, .Im = 0.520000 }; */
	info->julia_c = (t_cnb) {.Re = -0.3, .Im = -0.63 };
}

void	make_julia(t_info *info, t_cnb z)
{
	float norm,tmp;

	norm = z.Re * z.Re + z.Im * z.Im;
	tmp = 0;
	while (++(info->depth) < info->max && norm < 4.0)
	{
		tmp = z.Re;
		z.Re = z.Re * z.Re - z.Im * z.Im + info->julia_c.Re;
		z.Im = 2.0 * z.Im * tmp + info->julia_c.Im;
		norm = z.Re * z.Re + z.Im * z.Im;
	}
}
