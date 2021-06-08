/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 14:54:00 by yoinoue           #+#    #+#             */
/*   Updated: 2021/02/15 00:15:56 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_dir_and_plane_ne(t_vars *vars_p, int x, int y)
{
	if (vars_p->info.map[y][x] == 'N')
	{
		vars_p->vct.dirx = 0.0;
		vars_p->vct.diry = -1.0;
		vars_p->vct.planex = 0.66;
		vars_p->vct.planey = 0.0;
	}
	else if (vars_p->info.map[y][x] == 'E')
	{
		vars_p->vct.dirx = 1.0;
		vars_p->vct.diry = 0.0;
		vars_p->vct.planex = 0.0;
		vars_p->vct.planey = 0.66;
	}
}

void	set_dir_and_plane_ws(t_vars *vars_p, int x, int y)
{
	if (vars_p->info.map[y][x] == 'W')
	{
		vars_p->vct.dirx = -1.0;
		vars_p->vct.diry = 0.0;
		vars_p->vct.planex = 0.0;
		vars_p->vct.planey = -0.66;
	}
	else if (vars_p->info.map[y][x] == 'S')
	{
		vars_p->vct.dirx = 0.0;
		vars_p->vct.diry = 1.0;
		vars_p->vct.planex = -0.66;
		vars_p->vct.planey = 0.0;
	}
}
