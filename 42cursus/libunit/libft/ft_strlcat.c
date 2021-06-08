/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 22:32:03 by yoinoue           #+#    #+#             */
/*   Updated: 2020/06/25 18:09:35 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	l;
	unsigned int	m;

	m = ft_strlen(src);
	l = 0;
	while (size != 0 && *dst != '\0')
	{
		dst++;
		size--;
		l++;
	}
	if (size == 0)
		return (l + m);
	while (*src != '\0' && size > 1)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	*dst = '\0';
	return (l + m);
}
