/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 22:31:42 by yoinoue           #+#    #+#             */
/*   Updated: 2020/07/04 22:56:13 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t size)
{
	char		*c1;
	const char	*c2;

	if (s1 == s2 || size == 0)
		return (s1);
	c1 = (char *)s1;
	c2 = (const char *)s2;
	if (c1 < c2)
	{
		while (size--)
			*c1++ = *c2++;
	}
	else
	{
		c1 += size - 1;
		c2 += size - 1;
		while (size--)
			*c1-- = *c2--;
	}
	return (s1);
}
