/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_fill_tex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 23:35:16 by yoinoue           #+#    #+#             */
/*   Updated: 2021/02/10 23:23:05 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	fill_no(t_vars *vars_p, char *map_info)
{
	int	fd;
	int	len_no;

	len_no = 0;
	while (*map_info != '\0' && len_no++ < 2)
		map_info++;
	while (*map_info == ' ')
		map_info++;
	if ((fd = open(map_info, O_RDONLY)) < 0 || close(fd) < 0)
		return (error_check(MAP_ERROR));
	if (fd >= 0)
		vars_p->info.path_n = ft_strdup(map_info);
	while (*map_info != ' ' && *map_info != '\0')
		map_info++;
	if (*map_info == ' ')
	{
		while (*map_info != '\0')
		{
			if (*map_info != ' ')
				return (error_check(MAP_ERROR));
			map_info++;
		}
	}
	return (0);
}

int	fill_so(t_vars *vars_p, char *map_info)
{
	int	fd;
	int	len_so;

	len_so = 0;
	while (*map_info != '\0' && len_so++ < 2)
		map_info++;
	while (*map_info == ' ')
		map_info++;
	if ((fd = open(map_info, O_RDONLY)) < 0 || close(fd) < 0)
		return (error_check(MAP_ERROR));
	if (fd >= 0)
		vars_p->info.path_s = ft_strdup(map_info);
	while (*map_info != ' ' && *map_info != '\0')
		map_info++;
	if (*map_info == ' ')
	{
		while (*map_info != '\0')
		{
			if (*map_info != ' ')
				return (error_check(MAP_ERROR));
			map_info++;
		}
	}
	return (0);
}

int	fill_we(t_vars *vars_p, char *map_info)
{
	int	fd;
	int	len_we;

	len_we = 0;
	while (*map_info != '\0' && len_we++ < 2)
		map_info++;
	while (*map_info == ' ')
		map_info++;
	if ((fd = open(map_info, O_RDONLY)) < 0 || close(fd) < 0)
		return (error_check(MAP_ERROR));
	if (fd >= 0)
		vars_p->info.path_w = ft_strdup(map_info);
	while (*map_info != ' ' && *map_info != '\0')
		map_info++;
	if (*map_info == ' ')
	{
		while (*map_info != '\0')
		{
			if (*map_info != ' ')
				return (error_check(MAP_ERROR));
			map_info++;
		}
	}
	return (0);
}

int	fill_ea(t_vars *vars_p, char *map_info)
{
	int	fd;
	int	len_ea;

	len_ea = 0;
	while (*map_info != '\0' && len_ea++ < 2)
		map_info++;
	while (*map_info == ' ')
		map_info++;
	if ((fd = open(map_info, O_RDONLY)) < 0 || close(fd) < 0)
		return (error_check(MAP_ERROR));
	if (fd >= 0)
		vars_p->info.path_e = ft_strdup(map_info);
	while (*map_info != ' ' && *map_info != '\0')
		map_info++;
	if (*map_info == ' ')
	{
		while (*map_info != '\0')
		{
			if (*map_info != ' ')
				return (error_check(MAP_ERROR));
			map_info++;
		}
	}
	return (0);
}

int	fill_s(t_vars *vars_p, char *map_info)
{
	int	fd;
	int	len_s;

	len_s = 0;
	while (*map_info != '\0' && len_s++ < 1)
		map_info++;
	while (*map_info == ' ')
		map_info++;
	if ((fd = open(map_info, O_RDONLY)) < 0 || close(fd) < 0)
		return (error_check(MAP_ERROR));
	if (fd >= 0)
		vars_p->info.path_sprite = ft_strdup(map_info);
	while (*map_info != ' ' && *map_info != '\0')
		map_info++;
	if (*map_info == ' ')
	{
		while (*map_info != '\0')
		{
			if (*map_info != ' ')
				return (error_check(MAP_ERROR));
			map_info++;
		}
	}
	return (0);
}
