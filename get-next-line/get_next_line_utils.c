/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 21:41:59 by yoinoue           #+#    #+#             */
/*   Updated: 2020/07/25 16:20:06 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	ret;
	int		i;

	ret = 0;
	i = 0;
	while (s[i++])
		ret++;
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	char	cc;
	char	*ret;

	cc = (char)c;
	while (*s)
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

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new;
	size_t	len;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (*s1)
		new[i++] = *s1++;
	while (*s2)
		new[i++] = *s2++;
	new[i] = '\0';
	return (new);
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*ret;
	int		i;

	len = 0;
	while (s[len])
		len++;
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = -1;
	while (s[++i])
		ret[i] = s[i];
	ret[i] = '\0';
	return (ret);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		if (!(sub = (char *)malloc(1 * sizeof(char))))
			return (NULL);
		return (sub);
	}
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (len-- && s[start])
		sub[i++] = (char)s[start++];
	sub[i] = '\0';
	return (sub);
}
