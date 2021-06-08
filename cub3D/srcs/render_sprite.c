/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 12:59:36 by yoinoue           #+#    #+#             */
/*   Updated: 2021/02/10 23:23:42 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	repeat_projection(t_vars *vars,
t_render_sp_vct *vct_data, int spriteorder[])
{
	calc_projection(vars, vct_data, spriteorder);
	if (vct_data->drawstarty < 0)
		vct_data->drawstarty = 0;
	vct_data->drawendy = vct_data->spriteheight / 2
			+ vars->screenheight / 2;
	if (vct_data->drawendy >= vars->screenheight)
		vct_data->drawendy = vars->screenheight - 1;
	vct_data->spritewidth = abs((int)(vars->screenheight
			/ vct_data->transformy));
	vct_data->drawstartx = -vct_data->spritewidth / 2
			+ vct_data->spritescreenx;
	if (vct_data->drawstartx < 0)
		vct_data->drawstartx = 0;
	vct_data->drawendx = vct_data->spritewidth / 2
			+ vct_data->spritescreenx;
	if (vct_data->drawendx >= vars->screenwidth)
		vct_data->drawendx = vars->screenwidth - 1;
	vct_data->stripe = vct_data->drawstartx - 1;
}

void	draw_sp(t_vars *vars, t_render_sp_vct *vct_data, double *zbuffer)
{
	vct_data->texx = (int)(256 * (vct_data->stripe - (-vct_data->spritewidth
		/ 2 + vct_data->spritescreenx))
		* vars->texture[SPRITE_TEXTURE].texwidth /
		vct_data->spritewidth) / 256;
	if (vct_data->transformy > 0 && vct_data->stripe > 0 && vct_data->stripe <
		vars->screenwidth && vct_data->transformy < zbuffer[vct_data->stripe])
	{
		vct_data->y = vct_data->drawstarty - 1;
		while (++(vct_data->y) < vct_data->drawendy)
		{
			vct_data->d = vct_data->y * 256 - vars->screenheight * 128
							+ vct_data->spriteheight * 128;
			vct_data->texy = ((vct_data->d
							* vars->texture[SPRITE_TEXTURE].texheight)
							/ vct_data->spriteheight) / 256;
			vct_data->color = my_get_pixel_color(&vars->texture[SPRITE_TEXTURE],
									vct_data->texx, vct_data->texy);
			if ((vct_data->color & 0x00FFFFFF) != 0)
				my_mlx_pixel_put(vars, vct_data->stripe,
									vct_data->y, vct_data->color);
		}
	}
}

void	bubble_sort_sp(t_vars *vars, t_sp_array array[])
{
	int		i;
	int		j;
	double	dist_tmp;
	int		order_tmp;

	i = -1;
	while (++i < vars->numsprites - 1)
	{
		j = -1;
		while (++j < vars->numsprites - 1)
		{
			if (array[j].dist > array[j + 1].dist)
			{
				dist_tmp = array[j].dist;
				array[j].dist = array[j + 1].dist;
				array[j + 1].dist = dist_tmp;
				order_tmp = array[j].order;
				array[j].order = array[j + 1].order;
				array[j + 1].order = order_tmp;
			}
		}
	}
}

void	sortsprites(t_vars *vars,
t_sp_array array[], int spriteorder[], double spritedistance[])
{
	int	i;

	i = -1;
	while (++i < vars->numsprites)
	{
		array[i].dist = spritedistance[i];
		array[i].order = spriteorder[i];
	}
	bubble_sort_sp(vars, array);
	i = -1;
	while (++i < vars->numsprites)
	{
		spritedistance[i] = array[vars->numsprites - i - 1].dist;
		spriteorder[i] = array[vars->numsprites - i - 1].order;
	}
}

void	render_sprite(t_vars *vars, double *zbuffer)
{
	t_sp_array		array[vars->numsprites];
	int				spriteorder[vars->numsprites];
	double			spritedistance[vars->numsprites];
	t_render_sp_vct	vct_data;

	vct_data.i = -1;
	while (++(vct_data.i) < vars->numsprites)
	{
		spriteorder[vct_data.i] = vct_data.i;
		spritedistance[vct_data.i] = ((vars->vct.posx -
		vars->sprite_data[vct_data.i].x) * (vars->vct.posx -
		vars->sprite_data[vct_data.i].x) + (vars->vct.posy -
		vars->sprite_data[vct_data.i].y) * (vars->vct.posy -
		vars->sprite_data[vct_data.i].y));
	}
	sortsprites(vars, array, spriteorder, spritedistance);
	vct_data.i = -1;
	while (++(vct_data.i) < vars->numsprites)
	{
		repeat_projection(vars, &vct_data, spriteorder);
		while (++(vct_data.stripe) < vct_data.drawendx)
			draw_sp(vars, &vct_data, zbuffer);
	}
}
