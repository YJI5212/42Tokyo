/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keydown.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 10:31:10 by yoinoue           #+#    #+#             */
/*   Updated: 2021/02/12 17:16:44 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_ws(t_vars *vars, double movespeed, int keycode)
{
	if (keycode == W || keycode == UP)
	{
		if (vars->info.map[(int)vars->vct.posy]
		[(int)(vars->vct.posx + vars->vct.dirx * movespeed)] == '!')
			vars->vct.posx += vars->vct.dirx * movespeed;
		if (vars->info.map[(int)(vars->vct.posy +
		vars->vct.diry * movespeed)][(int)vars->vct.posx] == '!')
			vars->vct.posy += vars->vct.diry * movespeed;
		my_mlx_put_image_to_window(vars, 0);
	}
	else if (keycode == S || keycode == DOWN)
	{
		if (vars->info.map[(int)vars->vct.posy]
		[(int)(vars->vct.posx - vars->vct.dirx * movespeed)] == '!')
			vars->vct.posx -= vars->vct.dirx * movespeed;
		if (vars->info.map[(int)(vars->vct.posy -
		vars->vct.diry * movespeed)][(int)vars->vct.posx] == '!')
			vars->vct.posy -= vars->vct.diry * movespeed;
		my_mlx_put_image_to_window(vars, 0);
	}
}

void	key_da(t_vars *vars, double movespeed, int keycode)
{
	if (keycode == D)
	{
		if (vars->info.map[(int)vars->vct.posy]
		[(int)(vars->vct.posx - vars->vct.diry * movespeed)] == '!')
			vars->vct.posx -= vars->vct.diry * movespeed;
		if (vars->info.map[(int)(vars->vct.posy +
		vars->vct.dirx * movespeed)][(int)vars->vct.posx] == '!')
			vars->vct.posy -= (-1) * vars->vct.dirx * movespeed;
		my_mlx_put_image_to_window(vars, 0);
	}
	else if (keycode == A)
	{
		if (vars->info.map[(int)vars->vct.posy]
		[(int)(vars->vct.posx + vars->vct.diry * movespeed)] == '!')
			vars->vct.posx += vars->vct.diry * movespeed;
		if (vars->info.map[(int)(vars->vct.posy -
		vars->vct.dirx * movespeed)][(int)vars->vct.posx] == '!')
			vars->vct.posy += (-1) * vars->vct.dirx * movespeed;
		my_mlx_put_image_to_window(vars, 0);
	}
}

void	key_l(t_vars *vars, double rotspeed)
{
	double olddirx;
	double oldplanex;

	olddirx = vars->vct.dirx;
	vars->vct.dirx = vars->vct.dirx * cos(-rotspeed)
						- vars->vct.diry * sin(-rotspeed);
	vars->vct.diry = olddirx * sin(-rotspeed) +
	vars->vct.diry * cos(-rotspeed);
	oldplanex = vars->vct.planex;
	vars->vct.planex = vars->vct.planex * cos(-rotspeed)
						- vars->vct.planey * sin(-rotspeed);
	vars->vct.planey = oldplanex * sin(-rotspeed) +
	vars->vct.planey * cos(-rotspeed);
	my_mlx_put_image_to_window(vars, 0);
}

void	key_r(t_vars *vars, double rotspeed)
{
	double olddirx;
	double oldplanex;

	olddirx = vars->vct.dirx;
	vars->vct.dirx = vars->vct.dirx * cos(rotspeed)
						- vars->vct.diry * sin(rotspeed);
	vars->vct.diry = olddirx * sin(rotspeed) +
	vars->vct.diry * cos(rotspeed);
	oldplanex = vars->vct.planex;
	vars->vct.planex = vars->vct.planex * cos(rotspeed)
						- vars->vct.planey * sin(rotspeed);
	vars->vct.planey = oldplanex * sin(rotspeed) +
	vars->vct.planey * cos(rotspeed);
	my_mlx_put_image_to_window(vars, 0);
}

int		keydown(int keycode, t_vars *vars)
{
	double	movespeed;
	double	rotspeed;

	movespeed = 0.4;
	rotspeed = 0.3;
	if (keycode == W || keycode == S ||
		keycode == UP || keycode == DOWN)
		key_ws(vars, movespeed, keycode);
	else if (keycode == D || keycode == A)
		key_da(vars, movespeed, keycode);
	else if (keycode == LEFT)
		key_l(vars, rotspeed);
	else if (keycode == RIGHT)
		key_r(vars, rotspeed);
	else if (keycode == ESC)
	{
		close_window(vars);
		exit(0);
	}
	return (0);
}
