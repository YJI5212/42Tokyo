/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 00:17:06 by yoinoue           #+#    #+#             */
/*   Updated: 2020/08/25 21:20:08 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cc;
	char	*ret;

	cc = (char)c;
	while (*s != '\0')
	{
		if (*s == cc)
			break ;
		s++;
	}
	if (*s == cc)
	{
		ret = (char *)s;
		return (ret);
	}
	return (NULL);
}
