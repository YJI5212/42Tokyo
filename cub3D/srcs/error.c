/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 22:40:38 by yoinoue           #+#    #+#             */
/*   Updated: 2021/02/10 23:22:41 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error_check(int my_errno)
{
	if (my_errno == INPUT_ERROR)
		printf("Error\nInput Error\n");
	else if (my_errno == MAP_ERROR)
		printf("Error\nMap Error\n");
	else if (my_errno == MEMORY_ERROR)
		printf("Error\nMemory Error\n");
	else if (my_errno == FILE_ERROR)
		printf("Error\nFile Error\n");
	return (-1);
}
