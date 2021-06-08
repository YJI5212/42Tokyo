/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 18:41:08 by yoinoue           #+#    #+#             */
/*   Updated: 2020/09/09 06:45:19 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_0x_left(char buf[], t_list *f_list, int *j)
{
	if (buf[*j] == f_list->sign || f_list->flags & ALT)
	{
		if (buf[*j] == f_list->sign)
		{
			ft_putchar(buf[(*j)--]);
			f_list->prcs++;
		}
		else
		{
			ft_putchar(buf[(*j)--]);
			ft_putchar(buf[(*j)--]);
			f_list->prcs += 2;
		}
	}
}

void	print_0x_right(char buf[], t_list *f_list, int *j, int *len)
{
	if (buf[*j] == f_list->sign || f_list->flags & ALT)
	{
		if (buf[*j] == f_list->sign)
		{
			ft_putchar(buf[(*j)--]);
			(*len)--;
		}
		else
		{
			ft_putchar(buf[(*j)--]);
			ft_putchar(buf[(*j)--]);
			(*len) -= 2;
		}
	}
}

void	prcs_zero_left(t_list *f_list, int len, int *width, int *tmp)
{
	while (f_list->prcs-- > len)
	{
		ft_putchar('0');
		(*width)--;
		(*tmp)++;
	}
}

void	prcs_zero_right(t_list *f_list, int len, int *tmp)
{
	while (f_list->prcs-- > len)
	{
		ft_putchar('0');
		(*tmp)++;
	}
}

void	right_fill_pad(int width, int len, t_list *f_list, int *tmp)
{
	while ((width > len) && (width-- > f_list->prcs))
	{
		if (((f_list->flags & ZERO) && (f_list->prcs < 0))
		|| f_list->width < f_list->prcs)
			ft_putchar('0');
		else
			ft_putchar(' ');
		(*tmp)++;
	}
}
