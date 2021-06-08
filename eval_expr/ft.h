/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 10:06:37 by yoinoue           #+#    #+#             */
/*   Updated: 2020/04/10 20:47:28 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>

int				eval_expr(char *str);
long long int	expr(char *str, int *i);
long long int	term(char *str, int *i);
long long int	factor(char *str, int *i);
long long int	number(char *str, int *i);
int				count_space(char *str);
int				ft_strlen(char *str);
void			ft_reformat(char *str, char *new_str);
void			ft_putchar(char c);
void			ft_putnbr(int nbr);

#endif
