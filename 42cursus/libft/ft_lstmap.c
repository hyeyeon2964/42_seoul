/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:01:45 by hmyoung           #+#    #+#             */
/*   Updated: 2020/11/16 16:18:19 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_lst;
	t_list *new_node;

	if (!lst || !f)
		return (NULL);
	if ((new_node = ft_lstnew(f(lst->content))) == NULL)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	new_lst = new_node;
	lst = lst->next;
	while (lst)
	{
		if ((new_node = ft_lstnew(f(lst->content))) == NULL)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&new_lst, new_node);
	}
	return (new_lst);
}
