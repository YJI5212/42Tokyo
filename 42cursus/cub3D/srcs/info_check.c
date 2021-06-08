/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:04:10 by yoinoue           #+#    #+#             */
/*   Updated: 2021/02/15 15:07:51 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_name(char *path)
{
	int fd;

	if ((fd = open(path, O_RDONLY)) < 0)
		return (error_check(FILE_ERROR));
	close(fd);
	while (*path)
		path++;
	if (*(path - 4) == '.' && *(path - 3) == 'c' &&
	*(path - 2) == 'u' && *(path - 1) == 'b')
		return (0);
	return (error_check(FILE_ERROR));
}

int	check_resolution(t_vars *vars_p, char *map_info)
{
	int	index;

	if (!map_info || *map_info != 'R')
		return (0);
	else if (*map_info == 'R' &&
	(vars_p->info.resolution[0] > 0 || vars_p->info.resolution[1] > 0))
		return (error_check(MAP_ERROR));
	index = 0;
	while (*(++map_info) != '\0')
	{
		while (*map_info == ' ')
			map_info++;
		if (*map_info == '\0')
			break ;
		if (!ft_isdigit(*map_info) || index >= 2)
			return (error_check(MAP_ERROR));
		while (ft_isdigit(*map_info))
			vars_p->info.resolution[index] =
				vars_p->info.resolution[index] * 10 + (*map_info++ - '0');
		map_info--;
		index++;
	}
	return (0);
}

int	check_tex_and_sprite(t_vars *vars_p, char *map_info)
{
	int i;

	if ((ft_strncmp(map_info, "NO", 2) && ft_strncmp(map_info, "SO", 2) &&
	ft_strncmp(map_info, "WE", 2) && ft_strncmp(map_info, "EA", 2) &&
	ft_strncmp(map_info, "S", 1)) || !map_info)
		return (0);
	i = 0;
	while (map_info[i])
		i++;
	if (map_info[i - 1] != 'm' || map_info[i - 2] != 'p'
	|| map_info[i - 3] != 'x' || map_info[i - 4] != '.')
		return (error_check(FILE_ERROR));
	if (!ft_strncmp(map_info, "NO", 2) && !vars_p->info.path_n)
		return (fill_no(vars_p, map_info));
	else if (!ft_strncmp(map_info, "SO", 2) && !vars_p->info.path_s)
		return (fill_so(vars_p, map_info));
	else if (!ft_strncmp(map_info, "WE", 2) && !vars_p->info.path_w)
		return (fill_we(vars_p, map_info));
	else if (!ft_strncmp(map_info, "EA", 2) && !vars_p->info.path_e)
		return (fill_ea(vars_p, map_info));
	else if (!ft_strncmp(map_info, "S", 1) && !vars_p->info.path_sprite)
		return (fill_s(vars_p, map_info));
	return (error_check(MAP_ERROR));
}

int	check_map_file(t_vars *vars_p, char *map_info, int flag)
{
	char	**tmp;

	if (flag == 1 && !*map_info)
		return (2);
	if (!*map_info || !map_info)
		return (0);
	if (ft_strchr("RSFC", *map_info) || flag == 2 ||
	!ft_strncmp("NO", map_info, 2) || !ft_strncmp("SO", map_info, 2) ||
	!ft_strncmp("WE", map_info, 2) || !ft_strncmp("EA", map_info, 2))
		return (error_check(MAP_ERROR));
	if (!ft_strchr(map_info, '0') && !ft_strchr(map_info, '1') &&
	!ft_strchr(map_info, '2') && !ft_strchr(map_info, 'N') &&
	!ft_strchr(map_info, 'S') && !ft_strchr(map_info, 'W') &&
	!ft_strchr(map_info, 'E'))
		return (error_check(MAP_ERROR));
	tmp = vars_p->info.map;
	vars_p->info.map = (char **)ft_ptrjoin(
			(const void **)vars_p->info.map, (const void *)map_info);
	free(tmp);
	/* free(map_info);
	map_info = NULL; */
	if (!vars_p->info.map)
		return (error_check(MEMORY_ERROR));
	return (1);
}

int	is_valid_color(int *color_array)
{
	int	index;

	index = 0;
	while (index < 3)
	{
		if (0 > color_array[index] || color_array[index] > 255)
			return (0);
		index++;
	}
	return (1);
}
