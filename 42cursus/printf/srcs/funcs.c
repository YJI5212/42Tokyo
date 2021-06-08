/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 19:16:18 by yoinoue           #+#    #+#             */
/*   Updated: 2020/09/09 07:22:31 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_integer(unsigned long n, int radix, t_list *f_list)
{
	char	*lower;
	char	*upper;
	int		pad;
	char	*symbol;

	lower = "0123456789abcdef";
	upper = "0123456789ABCDEF";
	pad = ' ';
	if (f_list->flags & CAPITAL)
		symbol = upper;
	else
		symbol = lower;
	if (n == 0 && f_list->prcs == 0)
		f_list->width = put_integer_special(f_list);
	else if (f_list->flags & LEFT)
		f_list->width = put_integer_left(n, radix, symbol, f_list);
	else
		f_list->width = put_integer_right(n, radix, symbol, f_list);
}

int		put_integer_left(unsigned long n, int radix,
char *symbol, t_list *f_list)
{
	char	buf[80];
	int		len;
	int		width;
	int		tmp;
	int		j;

	ft_bzero(buf, 80);
	if (radix == 16)
		len = fill_buf16(&buf, symbol, n, f_list);
	else
		len = fill_buf10(&buf, symbol, n, f_list);
	width = f_list->width;
	tmp = len;
	j = len - 1;
	print_0x_left(buf, f_list, &j);
	prcs_zero_left(f_list, len, &width, &tmp);
	while (buf[j])
		ft_putchar(buf[j--]);
	while (width-- > len)
	{
		ft_putchar(' ');
		tmp++;
	}
	return (tmp);
}

int		put_integer_right(unsigned long n, int radix,
char *symbol, t_list *f_list)
{
	char	buf[80];
	int		len;
	int		width;
	int		tmp;
	int		j;

	ft_bzero(buf, 80);
	if (radix == 16)
		len = fill_buf16(&buf, symbol, n, f_list);
	else
		len = fill_buf10(&buf, symbol, n, f_list);
	width = f_list->width;
	tmp = len;
	j = len - 1;
	if (width < f_list->prcs)
		width = f_list->prcs;
	right_non_prcs(f_list, buf, &j);
	if (buf[j] == f_list->sign && f_list->prcs > -1 && len < f_list->prcs)
		width--;
	right_fill_pad(width, len, f_list, &tmp);
	print_0x_right(buf, f_list, &j, &len);
	prcs_zero_right(f_list, len, &tmp);
	while (buf[j])
		ft_putchar(buf[j--]);
	return (tmp);
}

int		put_integer_special(t_list *f_list)
{
	int width;

	width = f_list->width;
	if (f_list->flags & ALT)
	{
		if (f_list->width >= 2)
			width -= 2;
		else if (f_list->width < 2)
		{
			f_list->width = 2;
			width = 0;
		}
	}
	while (width--)
		ft_putchar(' ');
	if (f_list->flags & ALT)
	{
		ft_putchar('0');
		ft_putchar('x');
	}
	return (f_list->width);
}
