/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 10:43:55 by yoinoue           #+#    #+#             */
/*   Updated: 2020/04/10 20:46:29 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

long long int	number(char *str, int *i)
{
	long long int n;

	n = 0;
	while ('0' <= str[*i] && str[*i] <= '9')
	{
		n = n * 10 + str[*i] - '0';
		(*i)++;
	}
	return (n);
}

long long int	factor(char *str, int *i)
{
	long long int ret;

	if (str[*i] != '(' && str[*i] != ')')
		return (number(str, i));
	(*i)++;
	ret = expr(str, i);
	(*i)++;
	return (ret);
}

long long int	term(char *str, int *i)
{
	long int	val;
	long int	val2;
	char		op;

	val = factor(str, i);
	while (str[*i] == '*' || str[*i] == '/' || str[*i] == '%')
	{
		op = str[*i];
		(*i)++;
		val2 = factor(str, i);
		if (op == '*')
			val *= val2;
		else if (op == '/')
			val /= val2;
		else
			val %= val2;
	}
	return (val);
}

long long int	expr(char *str, int *i)
{
	long long int	val;
	long long int	val2;
	char			op;

	val = term(str, i);
	while (str[*i] == '+' || str[*i] == '-')
	{
		op = str[*i];
		(*i)++;
		val2 = term(str, i);
		if (op == '+')
			val += val2;
		else
			val -= val2;
	}
	return (val);
}

int				eval_expr(char *str)
{
	char	*new_str;
	int		len;
	int		i;
	int		ret;

	len = ft_strlen(str) - count_space(str);
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	ft_reformat(str, new_str);
	i = 0;
	ret = (int)expr(new_str, &i);
	free(new_str);
	return (ret);
}
