/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 11:20:35 by yoinoue           #+#    #+#             */
/*   Updated: 2021/02/16 16:15:01 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		min(int data1, int data2)
{
	if (data1 < data2)
		return (data1);
	else
		return (data2);
}

void	wall_dda(t_vars *vars, t_render_w_vct *vct_data)
{
	while (vct_data->hit == 0)
	{
		if (vct_data->sidedistx < vct_data->sidedisty)
		{
			vct_data->sidedistx += vct_data->deltadistx;
			vct_data->mapx += vct_data->stepx;
			vct_data->side = 0;
		}
		else
		{
			vct_data->sidedisty += vct_data->deltadisty;
			vct_data->mapy += vct_data->stepy;
			vct_data->side = 1;
		}
		if (vars->info.map[vct_data->mapy][vct_data->mapx] > '0')
			vct_data->hit = 1;
	}
}

void	render_w_y(t_vars *vars, t_render_w_vct *vct_data, int x, int y)
{
	vct_data->texy = min((int)vct_data->texpos,
		(vars->texture[vct_data->texnum].texheight - 1));
	vct_data->texpos += vct_data->step;
	vct_data->color = my_get_pixel_color(&vars->texture[vct_data->texnum],
		vct_data->texx, vct_data->texy);
	if (vct_data->side == 1)
		vct_data->color = (vct_data->color >> 1) & 8355711;
	my_mlx_pixel_put(vars, x, y, vct_data->color);
}

void	render_walls(t_vars *vars, double *zbuffer)
{
	int				x;
	int				y;
	t_render_w_vct	vct_data;

	x = -1;
	while (++x < vars->screenwidth)
	{
		render_w_x1(vars, &vct_data, x);
		render_w_x2(vars, &vct_data);
		wall_dda(vars, &vct_data);
		render_w_x3(vars, &vct_data);
		render_w_x4(vars, &vct_data);
		y = vct_data.drawstart;
		while (y <= vct_data.drawend)
			render_w_y(vars, &vct_data, x, y++);
		zbuffer[x] = vct_data.perpwalldist;
	}
}
