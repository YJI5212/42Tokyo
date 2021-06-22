#include "fractol.h"

int main(int ac, char *av[])
{
	t_info info;

	if (ac != 2 || init_name(&info, av[1]))
	{
		ft_putendl_fd(RED"Usage: ./fractol [FRACTOL]"RESET, 1);
		ft_putendl_fd("[FRACTOL]: Mandelbrot, Julia", 1);
		exit(EXIT_FAILURE);
	}
	if (init_vars(&info))
	{
		ft_putendl_fd(RED"[ERROR] Failed to initialize variables."RESET, 1);
		exit(EXIT_FAILURE);
	}
	fractol(&info);
	my_mlx_hook(&info);
	//my_mlx_put_image_to_window();
	mlx_loop(info.mlx);
	exit(EXIT_SUCCESS);
}
