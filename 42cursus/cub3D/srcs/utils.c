/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:43:20 by yoinoue           #+#    #+#             */
/*   Updated: 2021/02/10 23:23:42 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	**ft_ptrjoin(const void **array, const void *new)
{
	void	*tmp;
	void	**ret;
	size_t	len;

	if (!array || !new)
		return (NULL);
	len = ft_ptrlen(array);
	ret = (void **)ft_calloc(len + 1 + 1, sizeof(void *));
	if (ret == NULL)
		return (NULL);
	tmp = ft_strdup(new);
	ft_ptrcpy(ret, array);
	ft_ptrcat(ret, tmp);
	return (ret);
}

size_t	ft_ptrlen(const void **array)
{
	size_t	ret;
	int		i;

	ret = 0;
	i = -1;
	while (array[++i])
		ret++;
	return (ret);
}

void	ft_ptrcpy(void **dst, const void **src)
{
	while (*src != NULL)
	{
		*dst = (void *)*src;
		dst++;
		src++;
	}
	*dst = NULL;
	return ;
}

void	ft_ptrcat(void **dst, const void *src)
{
	while (*dst != NULL)
		dst++;
	*dst++ = (void *)src;
	*dst = NULL;
	return ;
}

void	free_all(t_vars *vars)
{
	char	**head;

	head = vars->info.map;
	while (*(vars->info.map))
	{
		free(*(vars->info.map));
		vars->info.map++;
	}
	free(head);
	free(vars->sprite_data);
}
