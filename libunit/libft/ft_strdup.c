/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 22:31:56 by yoinoue           #+#    #+#             */
/*   Updated: 2020/07/24 11:07:31 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*ret;
	int		i;

	len = 0;
	while (s[len] != '\0')
		len++;
	ret = (char *)ft_calloc(len + 1, sizeof(char));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		ret[i] = s[i];
		i++;
	}
	return (ret);
}
