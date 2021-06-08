/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 22:15:52 by yoinoue           #+#    #+#             */
/*   Updated: 2020/07/09 05:40:30 by yoinoue          ###   ########.fr       */
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
