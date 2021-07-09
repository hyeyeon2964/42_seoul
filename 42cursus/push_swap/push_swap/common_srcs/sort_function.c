/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <hmyoung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:41:04 by hmyoung           #+#    #+#             */
/*   Updated: 2021/07/09 12:41:06 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two_a(t_struct *head_a, t_oper *op)
{
	t_struct	*temp_up;
	t_struct	*temp_down;

	temp_up = head_a->next;
	temp_down = temp_up->next;
	if (temp_up->value > temp_down->value)
		sa(head_a, op);
}

void	sort_two_b(t_struct *head_b, t_oper *op)
{
	t_struct	*temp_up;
	t_struct	*temp_down;

	temp_up = head_b->next;
	temp_down = temp_up->next;
	if (temp_up->value < temp_down->value)
		sb(head_b, op);
}

void	sort_three_a(t_struct *head_a, t_oper *op)
{
	int			max;
	t_struct	*temp;

	temp = head_a->next;
	max = find_max(head_a);
	while (temp->value != max)
		temp = temp->next;
	if (temp->next == NULL)
		sort_two_a(head_a, op);
	else if (temp->next->next == NULL)
	{
		rra(head_a, op);
		sort_two_a(head_a, op);
	}
	else
	{
		ra(head_a, op);
		sort_two_a(head_a, op);
	}
}

void	sort_three_b(t_struct *head_b, t_oper *op)
{
	int			min;
	t_struct	*temp;

	temp = head_b->next;
	min = find_min(head_b);
	while (temp->value != min)
		temp = temp->next;
	if (temp->next == NULL)
		sort_two_b(head_b, op);
	else if (temp->next->next == NULL)
	{
		rrb(head_b, op);
		sort_two_b(head_b, op);
	}
	else
	{
		rb(head_b, op);
		sort_two_b(head_b, op);
	}
}

void	sort_five(t_struct *head_a, t_struct *head_b, int len, t_oper *op)
{
	int			middle;
	int			i;

	i = len;
	middle = check_pivot(head_a, len);
	while (i--)
	{
		if (head_a->next->value < middle)
			pb(head_a, head_b, op);
		else
			ra(head_a, op);
	}
	sort_three_a(head_a, op);
	sort_two_b(head_b, op);
	pa(head_a, head_b, op);
	pa(head_a, head_b, op);
}
