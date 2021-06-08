/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 06:54:19 by yoinoue           #+#    #+#             */
/*   Updated: 2020/09/09 07:00:01 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_c(t_list *f_list, va_list ap)
{
	int i;
	int width;

	width = 0;
	f_list->type = C;
	i = get_signed(ap, f_list);
	if (f_list->width > 0)
		width = f_list->width - 1;
	if (f_list->flags & LEFT)
	{
		ft_putchar(i);
		while (width--)
			ft_putchar(' ');
	}
	else
	{
		while (width--)
			ft_putchar(' ');
		ft_putchar(i);
	}
}

void	ft_percent(t_list *f_list)
{
	int width;

	if (f_list->width == 0)
		f_list->width = 1;
	width = f_list->width;
	if (f_list->flags & LEFT)
	{
		ft_putchar('%');
		while (width-- > 1)
			ft_putchar(' ');
	}
	else
	{
		while (width-- > 1)
		{
			if (f_list->flags & ZERO)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
		ft_putchar('%');
	}
}
