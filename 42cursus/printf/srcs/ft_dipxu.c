/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dipxu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 22:28:14 by yoinoue           #+#    #+#             */
/*   Updated: 2020/09/09 06:51:39 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_di(t_list *f_list, va_list ap)
{
	long i;

	i = 0;
	i = (long)get_signed(ap, f_list);
	if (i < 0)
	{
		i *= -1;
		f_list->sign = '-';
	}
	put_integer(i, 10, f_list);
}

void	ft_p(t_list *f_list, va_list ap)
{
	unsigned long ptr;

	ptr = va_arg(ap, unsigned long);
	f_list->flags |= ALT;
	put_integer(ptr, 16, f_list);
}
