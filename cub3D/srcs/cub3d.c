/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 16:24:34 by yoinoue           #+#    #+#             */
/*   Updated: 2021/02/16 16:46:05 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game(char *argv[])
{
	t_vars	vars;
	int		filesize;

	if (info_init(&vars, argv[1]) == -1)
		return ;
	vars.mlx = mlx_init();
	if (set_screensize(&vars) == -1)
		return ;
	filesize = vars.screenwidth * vars.screenheight * 4 + BMP_HEADER_SIZE;
	vars.buf = (unsigned int *)ft_calloc(filesize -
						BMP_HEADER_SIZE, sizeof(unsigned int));
	if (!vars.buf)
	{
		error_check(MEMORY_ERROR);
		return ;
	}
	vars.win = mlx_new_window(vars.mlx, vars.screenwidth,
				vars.screenheight, "cub3D by yoinoue");
	my_mlx_put_image_to_window(&vars, 0);
	mlx_hook(vars.win, 17, 1L << 5, close_window, &vars);
	mlx_hook(vars.win, 2, 1L << 0, keydown, &vars);
	mlx_loop(vars.mlx);
}

int		game_save(char *argv[])
{
	t_vars	vars;
	int		fd;
	int		filesize;

	if (info_init(&vars, argv[1]) == -1)
		return (-1);
	vars.mlx = mlx_init();
	if (set_screensize(&vars) == -1)
		return (-1);
	fd = open("Saved.bmp", O_CREAT | O_WRONLY | O_TRUNC,
						S_IRWXU | S_IRGRP | S_IROTH);
	if (fd < 0)
		return (error_check(FILE_ERROR));
	filesize = vars.screenwidth * vars.screenheight * 4
					+ BMP_HEADER_SIZE;
	vars.buf = (unsigned int *)ft_calloc(filesize - BMP_HEADER_SIZE,
						sizeof(unsigned int));
	if (!vars.buf)
		return (error_check(MEMORY_ERROR));
	my_mlx_put_image_to_window(&vars, 1);
	if (bmp_process(vars, filesize, fd) == -1)
		return (-1);
	return (0);
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		game(argv);
	else if (argc == 3 && ft_strncmp(argv[2], "--save", 7) == 0)
		game_save(argv);
	else
		error_check(INPUT_ERROR);

	while (1);

	return (0);
}
