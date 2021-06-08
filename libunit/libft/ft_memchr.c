/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 22:31:29 by yoinoue           #+#    #+#             */
/*   Updated: 2020/07/14 21:47:03 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t n)
{
	char	*cbuf;
	char	cc;
	void	*ret;
	size_t	i;
	int		flag;

	cbuf = (char *)buf;
	cc = (char)c;
	i = 0;
	flag = 0;
	while (i != n)
	{
		if (cbuf[i] == cc)
		{
			flag = 1;
			break ;
		}
		i++;
	}
	if (flag == 0)
		return (NULL);
	ret = (void *)(&cbuf[i]);
	return (ret);
}
