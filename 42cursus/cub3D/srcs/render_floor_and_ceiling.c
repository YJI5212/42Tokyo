/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_floor_and_ceiling.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 10:46:03 by yoinoue           #+#    #+#             */
/*   Updated: 2021/02/10 23:23:42 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_set_mlx(t_vars *vars)
{
	vars->img.img = mlx_new_image(vars->mlx,
								vars->screenwidth,
								vars->screenheight);
	vars->img.addr = mlx_get_data_addr(
						vars->img.img,
						&vars->img.bits_per_pixel,
						&vars->img.line_length,
						&vars->img.endian);
}

void	render_fc_y(t_vars *vars, int y, t_render_fc_vct *vct_data)
{
	vct_data->raydirx0 = vars->vct.dirx - vars->vct.planex;
	vct_data->raydiry0 = vars->vct.diry - vars->vct.planey;
	vct_data->raydirx1 = vars->vct.dirx + vars->vct.planex;
	vct_data->raydiry1 = vars->vct.diry + vars->vct.planey;
	vct_data->p = y - vars->screenheight / 2;
	vct_data->posz = 0.5 * vars->screenheight;
	vct_data->rowdistance = vct_data->posz / vct_data->p;
	vct_data->floorstepx = vct_data->rowdistance
			* (vct_data->raydirx1 - vct_data->raydirx0) / vars->screenwidth;
	vct_data->floorstepy = vct_data->rowdistance
			* (vct_data->raydiry1 - vct_data->raydiry0) / vars->screenwidth;
	vct_data->floorx = vars->vct.posx +
			vct_data->rowdistance * vct_data->raydirx0;
	vct_data->floory = vars->vct.posy +
			vct_data->rowdistance * vct_data->raydiry0;
}

void	render_fc_x(t_vars *vars, int x, int y, t_render_fc_vct *vct_data)
{
	vct_data->floorx += vct_data->floorstepx;
	vct_data->floory += vct_data->floorstepy;
	vct_data->color = (vars->info.floor_rgb[0] << 16) |
		(vars->info.floor_rgb[1] << 8) | vars->info.floor_rgb[2];
	vct_data->color = (vct_data->color >> 1) & 8355711;
	my_mlx_pixel_put(vars, x, y, vct_data->color);
	vct_data->color = (vars->info.ceiling_rgb[0] << 16) |
		(vars->info.ceiling_rgb[1] << 8) | vars->info.ceiling_rgb[2];
	my_mlx_pixel_put(vars, x, vars->screenheight - y - 1, vct_data->color);
}

void	render_floor_and_ceiling(t_vars *vars)
{
	int				x;
	int				y;
	t_render_fc_vct	vct_data;

	render_set_mlx(vars);
	fill_texture(vars);
	y = -1;
	while (++y < vars->screenheight)
	{
		render_fc_y(vars, y, &vct_data);
		x = -1;
		while (++x < vars->screenwidth)
			render_fc_x(vars, x, y, &vct_data);
	}
}
