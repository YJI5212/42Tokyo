/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 19:17:48 by yoinoue           #+#    #+#             */
/*   Updated: 2021/02/15 16:58:27 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_copy(t_vars *vars_p, t_sp_data *tmp, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		vars_p->sprite_data[i] = tmp[i];
}

int		get_pos(t_vars *vars_p, int x, int y, int i)
{
	t_sp_data	*tmp;
	t_sp_data	new;

	tmp = NULL;
	if (vars_p->vct.posx != 0 && vars_p->info.map[y][x] != '2')
		return (error_check(MAP_ERROR));
	if (ft_strchr("NSWE", vars_p->info.map[y][x]))
	{
		vars_p->vct.posx = (double)x + 0.5;
		vars_p->vct.posy = (double)y + 0.5;
	}
	else if (vars_p->info.map[y][x] == '2')
	{
		new.x = (double)x + 0.5;
		new.y = (double)y + 0.5;
		tmp = vars_p->sprite_data;
		vars_p->sprite_data = (t_sp_data *)ft_calloc(i + 2, sizeof(t_sp_data));
		sprite_copy(vars_p, tmp, i);
		free(tmp);
		if (!vars_p->sprite_data)
			return (error_check(MEMORY_ERROR));
		vars_p->sprite_data[i] = new;
	}
	return (0);
}

int		check_map_flood_fill(char **map, int x, int y, int *flag)
{
	if (x == 0 || y == 0)
		return (*flag = error_check(MAP_ERROR));
	if (!ft_strchr("012!$", map[y][x + 1]))
		return (*flag = error_check(MAP_ERROR));
	if (!ft_strchr("012!$", map[y][x - 1]))
		return (*flag = error_check(MAP_ERROR));
	if (!ft_strchr("012!$", map[y + 1][x]))
		return (*flag = error_check(MAP_ERROR));
	if (!ft_strchr("012!$", map[y - 1][x]))
		return (*flag = error_check(MAP_ERROR));
	if (map[y][x] == '0')
		map[y][x] = '!';
	else if (map[y][x] == '2')
		map[y][x] = '$';
	if (*flag != -1 && ft_strchr("02", map[y][x + 1]))
		check_map_flood_fill(map, x + 1, y, flag);
	if (*flag != -1 && ft_strchr("02", map[y][x - 1]))
		check_map_flood_fill(map, x - 1, y, flag);
	if (*flag != -1 && ft_strchr("02", map[y + 1][x]))
		check_map_flood_fill(map, x, y + 1, flag);
	if (*flag != -1 && ft_strchr("02", map[y - 1][x]))
		check_map_flood_fill(map, x, y - 1, flag);
	return (*flag);
}

int		search_player_and_sprite(t_vars *vars_p)
{
	t_search_pl_and_sp	st;

	vars_p->sprite_data = (t_sp_data *)ft_calloc(1, sizeof(t_sp_data));
	st.i = 0;
	st.y = -1;
	while (vars_p->info.map[++(st.y)])
	{
		st.x = -1;
		while (vars_p->info.map[st.y][++(st.x)])
		{
			if (ft_strchr("NSWE2", vars_p->info.map[st.y][st.x]))
			{
				if (get_pos(vars_p, st.x, st.y, (st.i)++) == -1)
					return (-1);
				set_dir_and_plane_ne(vars_p, st.x, st.y);
				set_dir_and_plane_ws(vars_p, st.x, st.y);
				if (ft_strchr("NSWE", vars_p->info.map[st.y][st.x]))
					vars_p->info.map[st.y][st.x] = '0';
			}
		}
	}
	if (vars_p->vct.posx == 0 || vars_p->vct.posy == 0)
		return (error_check(MAP_ERROR));
	return (vars_p->numsprites = st.i);
}
