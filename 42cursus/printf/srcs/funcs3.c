/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 19:08:04 by yoinoue           #+#    #+#             */
/*   Updated: 2020/09/09 07:24:11 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	right_non_prcs(t_list *f_list, char buf[], int *j)
{
	if ((f_list->flags & ZERO) && (f_list->prcs < 0))
	{
		if (buf[*j] == f_list->sign)
			ft_putchar(buf[(*j)--]);
	}
}

int		fill_buf16(char (*buf)[80], char *symbol,
unsigned long n, t_list *f_list)
{
	int ret;
	int radix;

	ret = 0;
	radix = 16;
	if (n == 0)
		(*buf)[ret++] = symbol[0];
	while (n > 0)
	{
		(*buf)[ret++] = symbol[n % radix];
		n /= radix;
	}
	if (f_list->sign && radix == 10)
		(*buf)[ret++] = f_list->sign;
	if (f_list->flags & ALT)
	{
		(*buf)[ret++] = 'x';
		(*buf)[ret++] = '0';
	}
	return (ret);
}

int		fill_buf10(char (*buf)[80], char *symbol,
unsigned long n, t_list *f_list)
{
	int ret;
	int radix;

	ret = 0;
	radix = 10;
	if (n == 0)
		(*buf)[ret++] = symbol[0];
	while (n > 0)
	{
		(*buf)[ret++] = symbol[n % radix];
		n /= radix;
	}
	if (f_list->sign && radix == 10)
		(*buf)[ret++] = f_list->sign;
	return (ret);
}
