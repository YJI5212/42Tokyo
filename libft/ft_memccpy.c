/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 22:31:23 by yoinoue           #+#    #+#             */
/*   Updated: 2020/07/14 21:47:16 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *buf1, const void *buf2, int c, size_t n)
{
	char	*cbuf1;
	char	*cbuf2;
	char	cc;
	size_t	i;
	int		flag;

	cbuf1 = (char *)buf1;
	cbuf2 = (char *)buf2;
	cc = (char)c;
	i = 0;
	flag = 0;
	while (i != n)
	{
		cbuf1[i] = cbuf2[i];
		if (cbuf2[i++] == cc)
		{
			flag = 1;
			break ;
		}
	}
	if (flag == 0)
		return (NULL);
	buf1 = (void *)(&cbuf1[i]);
	return (buf1);
}
