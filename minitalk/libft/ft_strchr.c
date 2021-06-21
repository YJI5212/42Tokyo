/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 22:31:52 by yoinoue           #+#    #+#             */
/*   Updated: 2020/07/04 22:57:00 by yoinoue          ###   ########.fr       */
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
