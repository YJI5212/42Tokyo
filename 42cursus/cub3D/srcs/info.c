/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 22:57:26 by yoinoue           #+#    #+#             */
/*   Updated: 2021/02/14 18:15:05 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_vars(t_vars *vars_p)
{
	vars_p->screenwidth = 0;
	vars_p->screenheight = 0;
	vars_p->info.resolution[0] = 0;
	vars_p->info.resolution[1] = 0;
	vars_p->info.path_n = NULL;
	vars_p->info.path_s = NULL;
	vars_p->info.path_w = NULL;
	vars_p->info.path_e = NULL;
	vars_p->info.path_sprite = NULL;
	vars_p->info.floor_rgb[0] = -1;
	vars_p->info.floor_rgb[1] = -1;
	vars_p->info.floor_rgb[2] = -1;
	vars_p->info.ceiling_rgb[0] = -1;
	vars_p->info.ceiling_rgb[1] = -1;
	vars_p->info.ceiling_rgb[2] = -1;
	vars_p->info.map = NULL;
	vars_p->vct.posx = 0;
	vars_p->vct.posy = 0;
}

int		in_map_check(t_vars *vars_p, char *map_info, int fd, int flag)
{
	int ret;

	if (check_all_key_exist(vars_p) == 1)
	{
		if ((ret = check_map_file(vars_p, map_info, flag)) == -1)
		{
			close(fd);
			return (-1);
		}
		return (ret);
	}
	return (0);
}

int		in_r_path_sp_fc_check(t_vars *vars_p, char *map_info, int fd)
{
	if (map_info)
	{
		if (check_all_key_exist(vars_p) == -1)
		{
			if ((!ft_strchr("RSFC", *map_info) &&
			ft_strncmp("NO", map_info, 2) && ft_strncmp("SO", map_info, 2) &&
			ft_strncmp("WE", map_info, 2) && ft_strncmp("EA", map_info, 2)) ||
			ft_isdigit(*map_info))
				return (error_check(MAP_ERROR));
		}
	}
	if (check_resolution(vars_p, map_info) == -1 ||
		check_tex_and_sprite(vars_p, map_info) == -1 ||
		check_floor_and_ceiling(vars_p, map_info) == -1)
	{
		close(fd);
		return (-1);
	}
	return (0);
}

int		final_check(t_vars *vars_p, int rc)
{
	int	flag;

	if (rc < 0)
		return (error_check(FILE_ERROR));
	if (!vars_p->info.map)
		return (error_check(MAP_ERROR));
	flag = 1;
	if (search_player_and_sprite(vars_p) == -1 ||
	check_map_flood_fill(vars_p->info.map, (int)vars_p->vct.posx,
						(int)vars_p->vct.posy, &flag) == -1)
		return (-1);
	return (0);
}

int		info_init(t_vars *vars_p, char *path)
{
	t_info_init	data;

	init_vars(vars_p);
	if (check_name(path) == -1)
		return (-1);
	data.fd = open(path, O_RDONLY);
	vars_p->info.map = (char **)ft_calloc(1, sizeof(char *));
	while ((data.rc = get_next_line(data.fd, &data.map_info)) != -1)
	{
		if (data.rc == 0)
			break ;
		if ((data.flag = in_map_check(vars_p, data.map_info,
		data.fd, data.flag)) == -1 ||
		in_r_path_sp_fc_check(vars_p, data.map_info, data.fd) == -1)
			return (-1);
		/* else if (data.flag == 1)
			continue ; */
		free(data.map_info);
		data.map_info = NULL;
	}
	free(data.map_info);
	close(data.fd);
	if (final_check(vars_p, data.rc) == -1)
		return (-1);
	return (0);
}
