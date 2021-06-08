/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 22:31:47 by yoinoue           #+#    #+#             */
/*   Updated: 2020/07/04 22:56:18 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int c, size_t size)
{
	unsigned char	*cbuf;
	unsigned char	cc;
	size_t			i;

	cbuf = (unsigned char *)buf;
	cc = (unsigned char)c;
	i = 0;
	while (i != size)
	{
		cbuf[i] = cc;
		i++;
	}
	return (buf);
}
