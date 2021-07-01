/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_function.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:15:59 by jung-lee          #+#    #+#             */
/*   Updated: 2021/07/01 12:27:00 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			sa(t_struct *head_a, t_oper *op)
{
	t_struct	*temp_up;
	t_struct	*temp_down;

	if ((head_a->next != NULL) && (head_a->next->next != NULL))
	{
		temp_up = head_a->next;
		temp_down = head_a->next->next;
		head_a->next = temp_down;
		temp_up->next = temp_down->next;
		head_a->next->next = temp_up;
	}
	add_op_list(op, "sa");
}

void			sb(t_struct *head_b, t_oper *op)
{
	t_struct	*temp_up;
	t_struct	*temp_down;

	if ((head_b->next != NULL) && (head_b->next->next != NULL))
	{
		temp_up = head_b->next;
		temp_down = head_b->next->next;
		head_b->next = temp_down;
		temp_up->next = temp_down->next;
		head_b->next->next = temp_up;
	}
	add_op_list(op, "sb");
}

void			ss(t_struct *head_a, t_struct *head_b, t_oper *op)
{
	sa(head_a, op);
	sb(head_b, op);
}
