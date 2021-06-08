/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 10:38:11 by yoinoue           #+#    #+#             */
/*   Updated: 2021/02/10 23:22:41 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_tex_ns(t_vars *vars)
{
	vars->texture[NORTH_TEXTURE].img = mlx_xpm_file_to_image(vars->mlx,
							vars->info.path_n,
							&vars->texture[NORTH_TEXTURE].texwidth,
							&vars->texture[NORTH_TEXTURE].texheight);
	vars->texture[NORTH_TEXTURE].addr = mlx_get_data_addr(
						vars->texture[NORTH_TEXTURE].img,
						&vars->texture[NORTH_TEXTURE].bits_per_pixel,
						&vars->texture[NORTH_TEXTURE].line_length,
						&vars->texture[NORTH_TEXTURE].endian);
	vars->texture[SOUTH_TEXTURE].img = mlx_xpm_file_to_image(vars->mlx,
							vars->info.path_s,
							&vars->texture[SOUTH_TEXTURE].texwidth,
							&vars->texture[SOUTH_TEXTURE].texheight);
	vars->texture[SOUTH_TEXTURE].addr = mlx_get_data_addr(
						vars->texture[SOUTH_TEXTURE].img,
						&vars->texture[SOUTH_TEXTURE].bits_per_pixel,
						&vars->texture[SOUTH_TEXTURE].line_length,
						&vars->texture[SOUTH_TEXTURE].endian);
}

void	fill_tex_ew(t_vars *vars)
{
	vars->texture[EAST_TEXTURE].img = mlx_xpm_file_to_image(vars->mlx,
							vars->info.path_e,
							&vars->texture[EAST_TEXTURE].texwidth,
							&vars->texture[EAST_TEXTURE].texheight);
	vars->texture[EAST_TEXTURE].addr = mlx_get_data_addr(
						vars->texture[EAST_TEXTURE].img,
						&vars->texture[EAST_TEXTURE].bits_per_pixel,
						&vars->texture[EAST_TEXTURE].line_length,
						&vars->texture[EAST_TEXTURE].endian);
	vars->texture[WEST_TEXTURE].img = mlx_xpm_file_to_image(vars->mlx,
							vars->info.path_w,
							&vars->texture[WEST_TEXTURE].texwidth,
							&vars->texture[WEST_TEXTURE].texheight);
	vars->texture[WEST_TEXTURE].addr = mlx_get_data_addr(
						vars->texture[WEST_TEXTURE].img,
						&vars->texture[WEST_TEXTURE].bits_per_pixel,
						&vars->texture[WEST_TEXTURE].line_length,
						&vars->texture[WEST_TEXTURE].endian);
}

void	fill_tex_sprite(t_vars *vars)
{
	vars->texture[SPRITE_TEXTURE].img = mlx_xpm_file_to_image(vars->mlx,
							vars->info.path_sprite,
							&vars->texture[SPRITE_TEXTURE].texwidth,
							&vars->texture[SPRITE_TEXTURE].texheight);
	vars->texture[SPRITE_TEXTURE].addr = mlx_get_data_addr(
						vars->texture[SPRITE_TEXTURE].img,
						&vars->texture[SPRITE_TEXTURE].bits_per_pixel,
						&vars->texture[SPRITE_TEXTURE].line_length,
						&vars->texture[SPRITE_TEXTURE].endian);
}

void	fill_texture(t_vars *vars)
{
	fill_tex_ns(vars);
	fill_tex_ew(vars);
	fill_tex_sprite(vars);
}
