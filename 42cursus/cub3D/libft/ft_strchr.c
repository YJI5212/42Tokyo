/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 22:31:52 by yoinoue           #+#    #+#             */
/*   Updated: 2021/02/06 13:55:56 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, char c)
{
	char	*ret;

	while (*s)
	{
		if (*s == c)
			break ;
		s++;
	}
	if (*s == c)
	{
		ret = (char *)s;
		return (ret);
	}
	return (NULL);
}
