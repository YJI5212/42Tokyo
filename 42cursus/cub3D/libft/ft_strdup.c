/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 22:31:56 by yoinoue           #+#    #+#             */
/*   Updated: 2020/12/13 23:30:40 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*ret;
	int		i;

	len = 0;
	while (s[len])
		len++;
	ret = (char *)ft_calloc(len + 1, sizeof(char));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ret[i] = s[i];
		i++;
	}
	return (ret);
}
