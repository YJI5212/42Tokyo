/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 14:14:49 by yoinoue           #+#    #+#             */
/*   Updated: 2021/02/10 23:23:42 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_vars *vars)
{
	free_all(vars);
	free(vars->buf);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	set_screensize(t_vars *vars)
{
	int	sizex;
	int	sizey;

	mlx_get_screen_size(vars->mlx, &sizex, &sizey);
	if (vars->info.resolution[0] > sizex)
		vars->screenwidth = sizex;
	else if (vars->info.resolution[0] <= sizex)
		vars->screenwidth = vars->info.resolution[0];
	if (vars->info.resolution[1] > sizey)
		vars->screenheight = sizey;
	else if (vars->info.resolution[1] <= sizey)
		vars->screenheight = vars->info.resolution[1];
	if (sizex == 0 || sizey == 0)
		return (error_check(INPUT_ERROR));
	return (0);
}
