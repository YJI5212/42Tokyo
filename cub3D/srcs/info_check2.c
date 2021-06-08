/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_check2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 14:57:10 by yoinoue           #+#    #+#             */
/*   Updated: 2021/02/12 17:27:48 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_floor(char *map_info, t_vars *vars_p, int *i)
{
	if (*map_info == 'F' && !is_valid_color(vars_p->info.floor_rgb))
	{
		if (*map_info)
			map_info++;
		while (*map_info == ' ' && *map_info)
			map_info++;
		while (ft_isdigit(*map_info))
		{
			if ((vars_p->info.floor_rgb[*i] = ft_atoi(map_info)) < 0 ||
			(vars_p->info.floor_rgb[*i] = ft_atoi(map_info)) > 255)
				return (-1);
			while (*map_info != ',' && *map_info != '\0'
			&& ft_isdigit(*map_info))
				map_info++;
			if (*map_info == '\0'
			|| !ft_strchr("1234567890,", *map_info))
				break ;
			if ((*i)++ < 2)
				map_info++;
		}
		if (!is_valid_color(vars_p->info.floor_rgb) || *map_info != '\0')
			return (-1);
		return (0);
	}
	return (-1);
}

int	check_ceiling(char *map_info, t_vars *vars_p, int *i)
{
	if (*map_info == 'C' && !is_valid_color(vars_p->info.ceiling_rgb))
	{
		if (*map_info)
			map_info++;
		while (*map_info == ' ' && *map_info)
			map_info++;
		while (ft_isdigit(*map_info))
		{
			if ((vars_p->info.ceiling_rgb[*i] = ft_atoi(map_info)) < 0 ||
			(vars_p->info.ceiling_rgb[*i] = ft_atoi(map_info)) > 255)
				return (-1);
			while (*map_info != ',' && *map_info != '\0'
			&& ft_isdigit(*map_info))
				map_info++;
			if (*map_info == '\0'
			|| !ft_strchr("1234567890,", *map_info))
				break ;
			if ((*i)++ < 2)
				map_info++;
		}
		if (!is_valid_color(vars_p->info.ceiling_rgb) || *map_info != '\0')
			return (-1);
		return (0);
	}
	return (-1);
}

int	check_floor_and_ceiling(t_vars *vars_p, char *map_info)
{
	int	i;

	i = 0;
	if (!ft_strchr("FC", *map_info) || !*map_info)
		return (0);
	if (check_floor(map_info, vars_p, &i) == 0)
		return (0);
	if (check_ceiling(map_info, vars_p, &i) == 0)
		return (0);
	return (error_check(MAP_ERROR));
}

int	check_all_key_exist(t_vars *vars_p)
{
	if ((vars_p->info.resolution[0] > 0 && vars_p->info.resolution[1] > 0) &&
		vars_p->info.path_n && vars_p->info.path_s &&
		vars_p->info.path_w && vars_p->info.path_e &&
		vars_p->info.path_sprite &&
		is_valid_color(vars_p->info.floor_rgb) &&
		is_valid_color(vars_p->info.ceiling_rgb))
		return (1);
	return (-1);
}
