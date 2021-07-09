/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_minmax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <hmyoung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:37:44 by hmyoung           #+#    #+#             */
/*   Updated: 2021/07/09 12:37:46 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_max(t_struct *head)
{
	int			max;
	t_struct	*temp;

	temp = head->next;
	max = temp->value;
	while (temp != NULL)
	{
		if (max < temp->value)
			max = temp->value;
		temp = temp->next;
	}
	return (max);
}

int	find_min(t_struct *head)
{
	int			min;
	t_struct	*temp;

	temp = head->next;
	min = temp->value;
	while (temp != NULL)
	{
		if (min > temp->value)
			min = temp->value;
		temp = temp->next;
	}
	return (min);
}
