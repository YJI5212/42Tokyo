/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 23:20:50 by yoinoue           #+#    #+#             */
/*   Updated: 2020/09/09 07:03:09 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*flag_check(const char *format, t_list *f_list)
{
	while (ft_strchr("-+ #0", *format))
	{
		if (*format == '-')
			f_list->flags |= LEFT;
		else if (*format == ' ')
			f_list->flags |= SPACE;
		else if (*format == '+')
			f_list->flags |= SIGN;
		else if (*format == '#')
			f_list->flags |= ALT;
		else if (*format == '0')
			f_list->flags |= ZERO;
		else if (*format == '\0')
			return (format);
		format++;
	}
	if (f_list->flags == SPACE)
		f_list->sign = ' ';
	else if (f_list->flags == SIGN || f_list->flags == 96)
		f_list->sign = '+';
	return (format);
}

static const char	*width_check(const char *format, t_list *f_list, va_list ap)
{
	if (*format == '*')
	{
		f_list->width = va_arg(ap, int);
		if (f_list->width < 0)
		{
			f_list->flags |= LEFT;
			f_list->width *= -1;
		}
		format++;
	}
	else
	{
		while (ft_isdigit(*format))
		{
			f_list->width = ((f_list->width) * 10) + (*format - '0');
			format++;
		}
	}
	return (format);
}

static const char	*prcs_check(const char *format, t_list *f_list, va_list ap)
{
	f_list->prcs = -1;
	if (*format == '.')
	{
		f_list->prcs = 0;
		format++;
		if (*format == '*')
		{
			f_list->prcs = va_arg(ap, int);
			format++;
		}
		else
		{
			while (ft_isdigit(*format))
			{
				f_list->prcs = ((f_list->prcs) * 10) + (*format - '0');
				format++;
			}
		}
	}
	return (format);
}

static const char	*mdfr_check(const char *format, t_list *f_list)
{
	f_list->type = 0;
	while (ft_strchr("hl", *format))
	{
		if (*format == 'h')
			f_list->type--;
		else if (*format == 'l')
			f_list->type++;
		else if (*format == '\0')
			return (format);
		format++;
	}
	return (format);
}

int					myformat(const char *format, va_list ap)
{
	int		size;
	t_list	f_list;

	size = 0;
	while (1)
	{
		ft_bzero(&f_list, sizeof(t_list));
		while (*format && *format != '%')
		{
			write(1, format++, 1);
			size++;
		}
		if (!*format)
			return (size);
		format++;
		format = flag_check(format, &f_list);
		format = width_check(format, &f_list, ap);
		format = prcs_check(format, &f_list, ap);
		format = mdfr_check(format, &f_list);
		format = spcf_check1(format, &f_list, ap);
		format = spcf_check2(format, &f_list, ap);
		size += f_list.width;
		if (*format != '\0' && ft_strchr("dipXxucs%", *format))
			format++;
	}
}
