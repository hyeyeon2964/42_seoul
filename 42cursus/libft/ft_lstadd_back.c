/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:36:19 by hmyoung           #+#    #+#             */
/*   Updated: 2020/11/16 16:24:58 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *temp;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		temp = *lst;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = new;
	}
}
