/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 23:30:48 by yoinoue           #+#    #+#             */
/*   Updated: 2021/02/10 23:24:01 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	header_init(char *header, t_vars vars, int filesize)
{
	int	addr;

	ft_memset(header, 0, BMP_HEADER_SIZE);
	ft_memcpy(&header[0], "BM", 2);
	ft_memcpy(&header[2], &filesize, 4);
	addr = BMP_HEADER_SIZE;
	ft_memcpy(&header[10], &addr, 4);
	addr = 40;
	ft_memcpy(&header[14], &addr, 4);
	ft_memcpy(&header[18], &(vars.screenwidth), 4);
	ft_memcpy(&header[22], &(vars.screenheight), 4);
	addr = 1;
	ft_memcpy(&header[26], &addr, 2);
	addr = 32;
	ft_memcpy(&header[28], &addr, 2);
	addr = filesize - BMP_HEADER_SIZE;
	ft_memcpy(&header[34], &addr, 4);
}

int		bmp_process(t_vars vars, int filesize, int fd)
{
	char	header[BMP_HEADER_SIZE];

	if (!vars.buf)
		return (-1);
	header_init(header, vars, filesize);
	write(fd, header, BMP_HEADER_SIZE);
	write(fd, vars.buf, filesize - BMP_HEADER_SIZE);
	close(fd);
	free(vars.buf);
	return (0);
}
