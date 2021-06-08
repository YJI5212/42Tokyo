/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 22:32:23 by yoinoue           #+#    #+#             */
/*   Updated: 2020/06/26 15:03:13 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, int size)
{
	int	k;
	int	n;
	int	flag;

	n = (int)ft_strlen(s2);
	if (n == 0)
		return ((char *)s1);
	k = 0;
	while (s1[k] != '\0' && k <= size - n)
	{
		if (s1[k] == s2[0])
		{
			flag = ft_strncmp(&s1[k], &s2[0], n);
			if (flag == 0)
				return ((char *)&s1[k]);
		}
		k++;
	}
	return (NULL);
}
