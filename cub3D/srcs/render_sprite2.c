/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 23:10:28 by yoinoue           #+#    #+#             */
/*   Updated: 2021/02/10 23:23:42 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_projection(
	t_vars *vars, t_render_sp_vct *vct_data, int spriteorder[])
{
	vct_data->spritex = vars->sprite_data[spriteorder[
							vct_data->i]].x - vars->vct.posx;
	vct_data->spritey = vars->sprite_data[spriteorder[
							vct_data->i]].y - vars->vct.posy;
	vct_data->invdet = 1.0 / (vars->vct.planex * vars->vct.diry
						- vars->vct.dirx * vars->vct.planey);
	vct_data->transformx = vct_data->invdet * (vars->vct.diry
			* vct_data->spritex - vars->vct.dirx * vct_data->spritey);
	vct_data->transformy = vct_data->invdet * (-vars->vct.planey
			* vct_data->spritex + vars->vct.planex * vct_data->spritey);
	vct_data->spritescreenx = (int)((vars->screenwidth / 2)
			* (1 + vct_data->transformx / vct_data->transformy));
	vct_data->spriteheight = abs((int)(vars->screenheight
			/ vct_data->transformy));
	vct_data->drawstarty = -vct_data->spriteheight / 2
			+ vars->screenheight / 2;
}
