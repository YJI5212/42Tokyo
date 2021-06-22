#include "fractol.h"

int	init_name(t_info *info, char *name)
{
	if (!ft_strncmp(name, "Mandelbrot", 11))
		info->name = Mandelbrot;
	else if (!ft_strncmp(name, "Julia", 6))
		info->name = Julia;
	else
		return (1);
	return (0);
}

int	init_vars(t_info *info)
{
	info->mlx = mlx_init();
	if (!info->mlx)
		ft_putendl_fd("[Error] Mlx can't be started.", 1);
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, TITLE);
	if (!info->win)
		ft_putendl_fd("[Error] Window can't be created.", 1);
	init_img(info);
	if (!info->img.img)
		ft_putendl_fd("[Error] Image can't be created.", 1);
	info->zoom = 200;
	info->color = 0;
	info->offset = (t_cmp) {.x = 0, .y = 0};
	init_set_case(info);
	return (0);
}

void	init_img(t_info *info)
{
	info->img.img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->img.addr
	= mlx_get_data_addr(info->img.img,
						&info->img.bits_per_pixel,
						&info->img.line_length,
						&info->img.endian);
}

void	init_set_case(t_info *info)
{
	if (info->name == Mandelbrot)
	{
		info->zoom = 80;
		info->max = 280;
	}
	else if (info->name == Julia)
	{
		info->zoom = 300;
		info->max = 300;
	}
}
