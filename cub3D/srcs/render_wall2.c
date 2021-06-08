/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 12:49:02 by yoinoue           #+#    #+#             */
/*   Updated: 2021/02/10 23:23:42 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_w_x1(t_vars *vars, t_render_w_vct *vct_data, int x)
{
	vct_data->camerax = 2 * x / (double)vars->screenwidth - 1;
	vct_data->raydirx = vars->vct.dirx + vars->vct.planex
		* vct_data->camerax;
	vct_data->raydiry = vars->vct.diry + vars->vct.planey
		* vct_data->camerax;
	vct_data->mapx = (int)vars->vct.posx;
	vct_data->mapy = (int)vars->vct.posy;
	vct_data->deltadistx = fabs(1 / vct_data->raydirx);
	vct_data->deltadisty = fabs(1 / vct_data->raydiry);
	vct_data->hit = 0;
}

void	render_w_x2(t_vars *vars, t_render_w_vct *vct_data)
{
	if (vct_data->raydirx < 0)
	{
		vct_data->stepx = -1;
		vct_data->sidedistx = (vars->vct.posx -
			vct_data->mapx) * vct_data->deltadistx;
	}
	else
	{
		vct_data->stepx = 1;
		vct_data->sidedistx = (vct_data->mapx + 1.0 -
			vars->vct.posx) * vct_data->deltadistx;
	}
	if (vct_data->raydiry < 0)
	{
		vct_data->stepy = -1;
		vct_data->sidedisty = (vars->vct.posy -
			vct_data->mapy) * vct_data->deltadisty;
	}
	else
	{
		vct_data->stepy = 1;
		vct_data->sidedisty = (vct_data->mapy + 1.0 -
			vars->vct.posy) * vct_data->deltadisty;
	}
}

void	render_w_x3(t_vars *vars, t_render_w_vct *vct_data)
{
	if (vct_data->side == 0)
		vct_data->perpwalldist = (vct_data->mapx - vars->vct.posx
				+ (1 - vct_data->stepx) / 2) / vct_data->raydirx;
	else
		vct_data->perpwalldist = (vct_data->mapy - vars->vct.posy
				+ (1 - vct_data->stepy) / 2) / vct_data->raydiry;
	vct_data->lineheight = (int)(vars->screenheight / vct_data->perpwalldist);
	vct_data->drawstart = -vct_data->lineheight / 2 + vars->screenheight / 2;
	if (vct_data->drawstart < 0)
		vct_data->drawstart = 0;
	vct_data->drawend = vct_data->lineheight / 2 +
			vars->screenheight / 2;
	if (vct_data->drawend >= vars->screenheight)
		vct_data->drawend = vars->screenheight - 1;
	if (vct_data->side == 0 && vct_data->raydirx >= 0)
		vct_data->texnum = EAST_TEXTURE;
	else if (vct_data->side == 0 && vct_data->raydirx < 0)
		vct_data->texnum = WEST_TEXTURE;
	else if (vct_data->side == 1 && vct_data->raydiry >= 0)
		vct_data->texnum = SOUTH_TEXTURE;
	else
		vct_data->texnum = NORTH_TEXTURE;
}

void	render_w_x4(t_vars *vars, t_render_w_vct *vct_data)
{
	if (vct_data->side == 0)
		vct_data->wallx = vars->vct.posy +
			vct_data->perpwalldist * vct_data->raydiry;
	else
		vct_data->wallx = vars->vct.posx +
			vct_data->perpwalldist * vct_data->raydirx;
	vct_data->wallx -= floor(vct_data->wallx);
	vct_data->texx = (int)(vct_data->wallx *
			(double)(vars->texture[vct_data->texnum].texwidth));
	if (vct_data->side == 0 && vct_data->raydirx > 0)
		vct_data->texx = vars->texture[vct_data->texnum].texwidth -
			vct_data->texx - 1;
	if (vct_data->side == 1 && vct_data->raydiry < 0)
		vct_data->texx = vars->texture[vct_data->texnum].texwidth -
			vct_data->texx - 1;
	vct_data->step = 1.0 * vars->texture[vct_data->texnum].texheight /
		vct_data->lineheight;
	vct_data->texpos = (vct_data->drawstart - vars->screenheight / 2 +
		vct_data->lineheight / 2) * vct_data->step;
}
