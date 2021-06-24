#include "fractol.h"

void	fractol(t_info *info)
{
	info->min.x = ((info->offset.x + (WIDTH >> 1)) / (info->zoom / 2.0)) / (-2);
	info->min.y = ((info->offset.y + (HEIGHT >> 1)) / (info->zoom / 2.0)) / (-2);
	info->cur.y = -1;
	while (++info->cur.y < HEIGHT)
	{
		info->cur.x = -1;
		while (++info->cur.x < WIDTH)
			draw(info);
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void	draw(t_info *info)
{
	t_cnb	z, c;

	c.Re = info->cur.x / info->zoom + info->min.x;
	c.Im = info->cur.y / info->zoom + info->min.y;
	z = (t_cnb) {.Re = 0, .Im = 0};
	info->depth = -1;
	if (info->name == Mandelbrot)
		make_mandelbrot(info, z, c);
	else if (info->name == Julia)
		make_julia(info, c);
	if (info->depth != info->max)
		my_mlx_pixel_put(info, info->cur.x, info->cur.y, BLACK);
	else
		my_mlx_pixel_put(info, info->cur.x, info->cur.y, CRIMSON);
		//my_mlx_pixel_put(info, info->cur.x, info->cur.y, color_calc(info));
}
