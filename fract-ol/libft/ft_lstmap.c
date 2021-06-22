/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 00:26:59 by yoinoue           #+#    #+#             */
/*   Updated: 2021/06/08 21:19:49 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new_emt;

	if (!lst || !f)
		return (NULL);
	new_emt = ft_lstnew(f(lst->content));
	if (!new_emt)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	new = NULL;
	while (lst)
	{
		new_emt = ft_lstnew(f(lst->content));
		if (!new_emt)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, new_emt);
		lst = lst->next;
	}
	return (new);
}
