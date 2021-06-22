#include "fractol.h"

#ifdef __MACH__

void	my_mlx_hook(t_info *info)
{
	//mlx_hook(info->win, 12, 1L << 15, my_mlx_put_image_to_window, info);
	mlx_hook(info->win, 02, 1L << 0, key_hook, info);
	mlx_mouse_hook(info->win, zoom_hook, info);
	mlx_hook(info->win, 06, 1L << 8, motion_hook, info);
	mlx_hook(info->win, CLOSE_BOTTON, 1L << 5, close_hook, info);
}

#else

void	my_mlx_hook(t_info *info)
{
	mlx_hook(info->win, 09, 2097152L, my_mlx_put_image_to_window, info);
	//mlx_hook(info->win, 12, 1L << 15, my_mlx_put_image_to_window, info);
	mlx_hook(info->win, 02, 1L << 0, keydown, info);
	mlx_hook(info->win, 06, 1L << 8, motion_hook, info);
}

#endif

void	my_mlx_pixel_put(t_info *info, int x, int y, int color)
{
	char *dst;

	if (0 <= x && x < WIDTH && 0 <= y && y < HEIGHT)
	{
		dst = info->img.addr + (y * info->img.line_length
					+ x * (info->img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

int	key_hook(int key, t_info *info)
{
	if (key == ESC)
	{
		mlx_destroy_window(info->mlx, info->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	zoom_hook(int button, int x, int y, t_info *info)
{
	double scale;

	scale = 0.0;
	if ((button == 1 || button == 2 || button == 4 || button == 5)
		&& (0 <= x && x < WIDTH && 0 <= y && y < HEIGHT))
	{
		/* button number 要チェック */
		if (button == 1 || button == 4)
			scale = 1.25;
		else if (button == 2 || button == 5)
			scale = 0.75;
		info->zoom *= scale;
		if (button == 1 || button == 2)
		{
			info->offset.x = round(info->offset.x + ((WIDTH >> 1) - x) * scale);
			info->offset.y = round(info->offset.y + ((HEIGHT >> 1) - y) * scale);
		}
		fractol(info);
	}
	return (0);
}

int	motion_hook(int x, int y, t_info *info)
{
	if (0 < x && x < WIDTH && 0 < y && y < HEIGHT)
	{
		info->julia_c.Re = (x + info->offset.x) / (double)info->zoom + info->min.x;
		info->julia_c.Im = (y + info->offset.y) / (double)info->zoom + info->min.y;
		fractol(info);
	}
	return (0);
}

int	close_hook(t_info *info)
{
	mlx_destroy_window(info->mlx, info->win);
	exit(EXIT_SUCCESS);
}
