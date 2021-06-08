/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 15:06:48 by yoinoue           #+#    #+#             */
/*   Updated: 2020/07/10 04:00:23 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	get_digit(long int n)
{
	unsigned int	digit;

	if (n == 0)
		return (1);
	digit = 0;
	if (n < 0)
	{
		n *= -1;
		digit++;
	}
	while (n > 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

static void			fill_ret(char *ret, long int ln, unsigned int digit)
{
	ret[digit] = '\0';
	if (ln == 0)
	{
		*ret = '0';
		return ;
	}
	while (ln > 0)
	{
		ret[--digit] = ln % 10 + '0';
		ln /= 10;
	}
	if (digit == 1)
		ret[0] = '-';
}

char				*ft_itoa(int n)
{
	char			*ret;
	unsigned int	digit;
	long int		ln;

	if (n < 0)
		ln = (long int)n * (-1);
	else
		ln = n;
	digit = get_digit((long int)n);
	if (!(ret = ft_calloc(digit + 1, sizeof(char))))
		return (NULL);
	fill_ret(ret, ln, digit);
	return (ret);
}
