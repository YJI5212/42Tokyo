/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 14:17:23 by yoinoue           #+#    #+#             */
/*   Updated: 2021/02/10 23:23:42 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char			*dst;
	unsigned int	*buf_ptr;
	int				mapy;

	dst = vars->img.addr + (y * vars->img.line_length
				+ x * (vars->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	mapy = vars->screenheight - y - 1;
	buf_ptr = vars->buf + vars->screenwidth * mapy;
	buf_ptr[x] = color;
}

int		my_get_pixel_color(t_tex *texture, int texx, int texy)
{
	char	*dst;

	dst = texture->addr + (texy * texture->line_length
				+ texx * (texture->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	my_mlx_put_image_to_window(t_vars *vars, int save_flag)
{
	double	*zbuffer;

	zbuffer = (double *)ft_calloc(vars->screenwidth, sizeof(double));
	render_floor_and_ceiling(vars);
	render_walls(vars, zbuffer);
	render_sprite(vars, zbuffer);
	if (!save_flag)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	free(zbuffer);
}
