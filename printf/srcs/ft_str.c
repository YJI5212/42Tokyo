/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 06:54:32 by yoinoue           #+#    #+#             */
/*   Updated: 2020/09/09 07:26:24 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_s(t_list *f_list, va_list ap)
{
	char	*s;
	int		len;
	int		width;
	int		ret;

	s = va_arg(ap, char *);
	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (f_list->prcs >= 0 && (f_list->prcs < len))
		len = f_list->prcs;
	width = f_list->width;
	if (f_list->flags & LEFT)
		ret = ft_s_left(width, len, s);
	else
		ret = ft_s_right(f_list, width, len, s);
	return (ret);
}

int	ft_s_left(int width, int len, char *s)
{
	int ret;

	ret = 0;
	while (len-- > 0)
	{
		ret++;
		width--;
		ft_putchar(*s++);
	}
	while (width > 0)
	{
		ret++;
		width--;
		ft_putchar(' ');
	}
	return (ret);
}

int	ft_s_right(t_list *f_list, int width, int len, char *s)
{
	int ret;

	ret = 0;
	while (width > len)
	{
		ret++;
		width--;
		if (f_list->flags & ZERO)
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
	while (len-- > 0)
	{
		ret++;
		ft_putchar(*s++);
	}
	return (ret);
}
