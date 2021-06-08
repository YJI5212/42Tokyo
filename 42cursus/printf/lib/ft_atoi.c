/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 00:14:27 by yoinoue           #+#    #+#             */
/*   Updated: 2020/08/08 00:16:11 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int flag;
	int n;

	flag = 1;
	n = 0;
	while (*str == ' ' || *str == '\t' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == '\n')
		str++;
	if (*str == '-')
	{
		flag = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		n *= 10;
		n += *str - '0';
		str++;
	}
	n = n * flag;
	return (n);
}
