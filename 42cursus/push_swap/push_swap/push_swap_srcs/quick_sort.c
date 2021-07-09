/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <hmyoung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:16:44 by hmyoung           #+#    #+#             */
/*   Updated: 2021/07/09 12:16:45 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	b_to_a(t_struct *head_a, t_struct *head_b, int n, t_oper *op)
{
	int			cnt;
	int			rb_cnt;
	int			temp;
	int			pivot;

	cnt = 0;
	rb_cnt = 0;
	if (n == 1)
	{
		pa(head_a, head_b, op);
		return ;
	}
	pivot = check_pivot(head_b, n);
	while (n--)
	{
		if (head_b->next->value > pivot)
			call_pa(head_a, head_b, &cnt, op);
		else
			call_rb(head_b, &rb_cnt, op);
	}
	temp = rb_cnt;
	while (temp--)
		rrb(head_b, op);
	a_to_b(head_a, head_b, cnt, op);
	b_to_a(head_a, head_b, rb_cnt, op);
}

void	a_to_b(t_struct *head_a, t_struct *head_b, int n, t_oper *op)
{
	int			ra_cnt;
	int			cnt;
	int			temp;
	int			pivot;

	ra_cnt = 0;
	cnt = 0;
	if (n == 1)
		return ;
	pivot = check_pivot(head_a, n);
	while (n--)
	{
		if (head_a->next->value > pivot)
			call_ra(head_a, &ra_cnt, op);
		else
			call_pb(head_a, head_b, &cnt, op);
	}
	temp = ra_cnt;
	while (temp--)
		rra(head_a, op);
	a_to_b(head_a, head_b, ra_cnt, op);
	b_to_a(head_a, head_b, cnt, op);
}
