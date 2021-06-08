/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 06:54:07 by yoinoue           #+#    #+#             */
/*   Updated: 2020/09/09 07:26:51 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../lib/libft.h"

# define ZERO     1
# define ALT      2
# define CAPITAL  4
# define SPACE    8
# define SIGN     16
# define LEFT     32

# define LL 2
# define L 1
# define I 0
# define S -1
# define C -2

typedef struct	s_list
{
	char	flags;
	char	sign;
	int		width;
	int		prcs;
	char	spcf;
	int		type;
}				t_list;

int				myformat(const char *format, va_list ap);
const char		*spcf_check2(const char *format, t_list *f_list, va_list ap);
const char		*spcf_check1(const char *format, t_list *f_list, va_list ap);

int				get_signed(va_list ap, t_list *f_list);
unsigned int	get_unsigned(va_list ap, t_list *f_list);
void			put_integer(unsigned long n, int radix, t_list *f_list);
int				put_integer_left(unsigned long n, int radix,
char *symbol, t_list *f_list);
int				put_integer_right(unsigned long n, int radix,
char *symbol, t_list *f_list);
int				put_integer_special(t_list *f_list);
int				fill_buf16(char (*buf)[80], char *symbol,
unsigned long n, t_list *f_list);
int				fill_buf10(char (*buf)[80], char *symbol,
unsigned long n, t_list *f_list);
void			print_0x_left(char buf[], t_list *f_list, int *j);
void			print_0x_right(char buf[], t_list *f_list, int *j, int *len);
void			prcs_zero_left(t_list *f_list, int len, int *width, int *tmp);
void			prcs_zero_right(t_list *f_list, int len, int *tmp);
void			right_fill_pad(int width, int len, t_list *f_list, int *tmp);
void			right_non_prcs(t_list *f_list, char buf[], int *j);

void			ft_c(t_list *f_list, va_list ap);
int				ft_s(t_list *f_list, va_list ap);
int				ft_s_left(int width, int len, char *s);
int				ft_s_right(t_list *f_list, int width, int len, char *s);
void			ft_percent(t_list *f_list);
void			ft_di(t_list *f_list, va_list ap);
void			ft_p(t_list *f_list, va_list ap);

int				ft_printf(const char *format, ...);

#endif
