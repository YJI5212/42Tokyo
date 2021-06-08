/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 22:31:37 by yoinoue           #+#    #+#             */
/*   Updated: 2020/07/09 06:17:13 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *buf1, const void *buf2, size_t n)
{
	unsigned char	*cbuf1;
	unsigned char	*cbuf2;

	cbuf1 = (unsigned char *)buf1;
	cbuf2 = (unsigned char *)buf2;
	if (n == 0 || buf1 == buf2)
		return (buf1);
	while (n--)
		*cbuf1++ = *cbuf2++;
	return (buf1);
}
