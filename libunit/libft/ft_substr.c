/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 15:06:04 by yoinoue           #+#    #+#             */
/*   Updated: 2020/07/24 11:07:24 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	if (start > ft_strlen(s))
	{
		if (!(sub = (char *)ft_calloc(1, sizeof(char))))
			return (NULL);
		return (sub);
	}
	sub = (char *)ft_calloc(len + 1, sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (len-- && s[start])
	{
		sub[i] = (char)s[start++];
		i++;
	}
	return (sub);
}
