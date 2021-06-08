/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 22:32:18 by yoinoue           #+#    #+#             */
/*   Updated: 2020/07/11 00:51:57 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t len)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	if (len == 0)
		return (0);
	i = 0;
	p1 = (unsigned char *)str1;
	p2 = (unsigned char *)str2;
	while (p1[i] == p2[i])
	{
		i++;
		if (p1[i] == '\0' || i == len)
			break ;
	}
	if (i == len)
		return (0);
	return (p1[i] - p2[i]);
}
