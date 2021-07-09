/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <hmyoung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:40:51 by hmyoung           #+#    #+#             */
/*   Updated: 2021/07/09 12:40:52 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sort_check_a(t_struct *head_a)
{
	t_struct	*temp;
	int			n;

	temp = head_a->next;
	while (temp->next != NULL)
	{
		n = temp->value;
		if (temp->next != NULL && n > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	sort_check_b(t_struct *head_b)
{
	t_struct	*temp;
	int			n;

	temp = head_b->next;
	while (temp->next != NULL)
	{
		n = temp->value;
		if (temp->next != NULL && n < temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	already_sort(t_struct *head)
{
	t_struct	*temp;
	int			n;

	temp = head->next;
	while (temp->next != NULL)
	{
		n = temp->value;
		if (temp->next != NULL && n > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}
