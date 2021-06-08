/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 21:41:57 by yoinoue           #+#    #+#             */
/*   Updated: 2020/08/25 22:49:45 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	fill_line(char **line, char **save)
{
	char	*nl;
	char	*tmp;

	nl = ft_strchr(*save, '\n');
	*line = ft_substr(*save, 0, nl ? nl - *save : ft_strlen(*save));
	tmp = *save;
	*save = nl ? ft_strdup(nl + 1) : NULL;
	free(tmp);
	if (!*line || (nl && !*save))
	{
		free(*line);
		free(*save);
		return (-1);
	}
	return (nl ? 1 : 0);
}

static int	reader(int fd, char **save)
{
	int		size;
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;

	if (!*save && !(*save = ft_strdup("")))
		return (-1);
	size = 0;
	while (!ft_strchr(*save, '\n'))
	{
		if ((size = read(fd, buf, BUFFER_SIZE)) < 0)
			return (-1);
		if (size == 0)
			return (0);
		buf[size] = '\0';
		tmp = *save;
		*save = ft_strjoin(*save, buf);
		free(tmp);
		if (!*save)
			return (-1);
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*save[OPEN_MAX];
	int			status;

	if (fd < 0 || !line)
		return (-1);
	if ((status = reader(fd, &save[fd])) != -1)
		status = fill_line(line, &save[fd]);
	return (status);
}
