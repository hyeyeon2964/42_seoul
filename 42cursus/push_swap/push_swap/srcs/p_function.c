/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_function.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:53:58 by jung-lee          #+#    #+#             */
/*   Updated: 2021/07/01 12:18:56 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			pa(t_struct *head_a, t_struct *head_b, t_oper *op)
{
	t_struct	*temp_a;
	t_struct	*temp_b;

	if (head_b->next != NULL)
	{
		temp_b = head_b->next;
		head_b->next = temp_b->next;
		temp_a = head_a->next;
		head_a->next = temp_b;
		temp_b->next = temp_a;
	}
	add_op_list(op, "pa");
}

void			pb(t_struct *head_a, t_struct *head_b, t_oper *op)
{
	t_struct	*temp_a;
	t_struct	*temp_b;

	if (head_a->next != NULL)
	{
		temp_a = head_a->next;
		head_a->next = temp_a->next;
		temp_b = head_b->next;
		temp_a->next = temp_b;
		head_b->next = temp_a;
	}
	add_op_list(op, "pb");
}
