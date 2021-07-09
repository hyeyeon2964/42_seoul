/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_after.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <hmyoung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:31:30 by hmyoung           #+#    #+#             */
/*   Updated: 2021/07/09 12:31:31 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	error_check_dup(t_struct *head)
{
	t_struct	*temp_i;
	t_struct	*temp_j;
	int			i;
	int			j;

	temp_i = head->next;
	while (temp_i->next != NULL)
	{
		i = temp_i->value;
		temp_j = temp_i->next;
		if (temp_j->next == NULL
			&& i == temp_j->value)
			return (1);
		while (temp_j != NULL)
		{
			j = temp_j->value;
			if (i == j)
				return (1);
			temp_j = temp_j->next;
		}
		temp_i = temp_i->next;
	}
	return (0);
}

int	error_check_after(t_struct *head)
{
	if (error_check_dup(head))
		return (1);
	if (already_sort(head))
		exit(0);
	return (0);
}
