/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 19:07:50 by yoinoue           #+#    #+#             */
/*   Updated: 2020/08/24 02:07:11 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_vprintf(const char *format, va_list ap)
{
	int		size;

	size = 0;
	if ((size = myformat(format, ap)) == -1)
		return (0);
	return (size);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	if (!format)
		return (0);
	va_start(ap, format);
	ret = ft_vprintf(format, ap);
	va_end(ap);
	return (ret);
}
