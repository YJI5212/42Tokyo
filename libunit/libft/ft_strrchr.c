/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 22:32:27 by yoinoue           #+#    #+#             */
/*   Updated: 2020/06/26 14:50:08 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int chr)
{
	unsigned char	cchr;
	char			*tmp;

	cchr = (unsigned char)chr;
	if (cchr == '\0')
	{
		while (*str)
			str++;
		return ((char *)str);
	}
	tmp = 0;
	while (*str)
	{
		if (*str == cchr)
			tmp = (char *)str;
		str++;
	}
	return (tmp);
}
