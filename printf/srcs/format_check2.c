/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_check2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 03:05:41 by yoinoue           #+#    #+#             */
/*   Updated: 2020/09/08 17:31:25 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*spcf_check2(const char *format, t_list *f_list, va_list ap)
{
	if (*format == 'c')
	{
		ft_c(f_list, ap);
		if (f_list->width == 0)
			f_list->width = 1;
	}
	else if (*format == 's')
		f_list->width = ft_s(f_list, ap);
	else if (*format == '%')
		ft_percent(f_list);
	return (format);
}

const char	*spcf_check1(const char *format, t_list *f_list, va_list ap)
{
	int				i;
	unsigned int	ui;

	i = 0;
	ui = 0;
	if (*format == 'd' || *format == 'i')
		ft_di(f_list, ap);
	else if (*format == 'p')
		ft_p(f_list, ap);
	else if (*format == 'X' || *format == 'x' || *format == 'u')
	{
		if (*format == 'X')
			f_list->flags |= CAPITAL;
		ui = get_unsigned(ap, f_list);
		if (*format == 'u')
			put_integer(ui, 10, f_list);
		else
			put_integer(ui, 16, f_list);
	}
	return (format);
}
