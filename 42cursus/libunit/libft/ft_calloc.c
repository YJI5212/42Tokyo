/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 22:29:36 by yoinoue           #+#    #+#             */
/*   Updated: 2020/07/04 22:54:45 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void *ptr;

	if (num == 0 || size == 0)
	{
		num = 1;
		size = 1;
	}
	ptr = (void *)malloc(num * size);
	if (ptr)
		ft_bzero(ptr, num * size);
	return (ptr);
}
