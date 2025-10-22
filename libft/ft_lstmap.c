/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:11:33 by becanals          #+#    #+#             */
/*   Updated: 2025/09/30 18:26:42 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*iter;

	if (!lst)
		return (NULL);
	first = ft_lstnew(f(lst->content));
	if (!first)
		return (NULL);
	iter = first;
	lst = lst->next;
	while (lst)
	{
		iter->next = ft_lstnew(f(lst->content));
		iter = iter->next;
		if (!iter)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (first);
}
