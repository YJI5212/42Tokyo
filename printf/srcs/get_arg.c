/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 19:15:39 by yoinoue           #+#    #+#             */
/*   Updated: 2020/09/08 19:15:43 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				get_signed(va_list ap, t_list *f_list)
{
	int t;

	t = f_list->type;
	if (t >= LL)
		t = LL;
	else if (t <= C)
		t = C;
	if (t == LL)
		return (va_arg(ap, long long));
	else if (t == L)
		return (va_arg(ap, long));
	else if (t == I)
		return (va_arg(ap, int));
	else if (t == S)
		return ((short)va_arg(ap, unsigned));
	else
		return ((char)va_arg(ap, unsigned));
}

unsigned int	get_unsigned(va_list ap, t_list *f_list)
{
	int t;

	t = f_list->type;
	if (t >= LL)
		t = LL;
	else if (t <= C)
		t = C;
	if (t == LL)
		return ((unsigned)va_arg(ap, long long));
	else if (t == L)
		return ((unsigned)va_arg(ap, long));
	else if (t == I)
		return ((unsigned)va_arg(ap, int));
	else if (t == S)
		return ((unsigned short)va_arg(ap, unsigned));
	else
		return ((unsigned char)va_arg(ap, unsigned));
}
