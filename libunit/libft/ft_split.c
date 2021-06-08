/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 15:06:40 by yoinoue           #+#    #+#             */
/*   Updated: 2020/07/12 14:37:49 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count(const char *head, char c)
{
	unsigned int	ret;
	const char		*tail;

	ret = 0;
	tail = head;
	while (*head)
	{
		if (*tail == c || *tail == '\0')
		{
			if (head < tail)
				ret++;
			if (*tail == '\0')
				break ;
			head = tail + 1;
		}
		tail++;
	}
	return (ret);
}

static unsigned int	fill_str(char **ret, const char *head, char c)
{
	unsigned int	i;
	const char		*tail;

	tail = head;
	i = 0;
	while (*head)
	{
		if (*tail == c || *tail == '\0')
		{
			if (head < tail)
			{
				if (!(*ret = ft_calloc((tail - head + 1), sizeof(char))))
					break ;
				ft_strlcpy(*(ret++), head, tail - head + 1);
				i++;
			}
			if (*tail == '\0')
				break ;
			head = tail + 1;
		}
		tail++;
	}
	*ret = NULL;
	return (i);
}

char				**ft_split(const char *s, char c)
{
	char			**ret;
	unsigned int	size;
	unsigned int	i;

	if (!s)
		return (NULL);
	size = count(s, c);
	if (!(ret = (char **)malloc((size + 1) * sizeof(char *))))
		return (NULL);
	if ((i = fill_str(ret, s, c)) < size)
	{
		while (i > 0)
			free(ret[--i]);
		free(ret);
		return (NULL);
	}
	return (ret);
}
