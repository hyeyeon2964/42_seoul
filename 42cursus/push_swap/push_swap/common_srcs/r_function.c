/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_function.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <hmyoung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:40:07 by hmyoung           #+#    #+#             */
/*   Updated: 2021/07/09 12:40:08 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_struct *head_a, t_oper *op)
{
	t_struct	*temp;
	t_struct	*last;

	if ((head_a->next != NULL) && (head_a->next->next != NULL))
	{
		temp = head_a->next;
		last = find_lst_last(head_a);
		head_a->next = temp->next;
		last->next = temp;
		temp->next = NULL;
	}
	add_op_list(op, "ra");
}

void	rb(t_struct *head_b, t_oper *op)
{
	t_struct	*temp;
	t_struct	*last;

	if ((head_b->next != NULL) && (head_b->next->next != NULL))
	{
		temp = head_b->next;
		last = find_lst_last(head_b);
		head_b->next = temp->next;
		last->next = temp;
		temp->next = NULL;
	}
	add_op_list(op, "rb");
}

void	rr(t_struct *head_a, t_struct *head_b, t_oper *op)
{
	ra(head_a, op);
	rb(head_b, op);
}
