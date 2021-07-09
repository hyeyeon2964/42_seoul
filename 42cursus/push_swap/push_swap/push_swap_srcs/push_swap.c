/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <hmyoung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:14:34 by hmyoung           #+#    #+#             */
/*   Updated: 2021/07/09 12:14:36 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_struct *head_a, t_struct *head_b, t_oper *op)
{
	int			n;

	n = size_of_list(head_a);
	if (n == 2)
		sort_two_a(head_a, op);
	else if (n == 3)
		sort_three_a(head_a, op);
	else if (n == 5)
		sort_five(head_a, head_b, n, op);
	else
		a_to_b(head_a, head_b, n, op);
}

int	main(int argc, char **argv)
{
	t_struct	*head_a;
	t_struct	*head_b;
	t_oper		*op;

	if (error_check_before(argc, argv))
		return (write_error());
	head_a = (t_struct *)malloc(sizeof(t_struct));
	head_b = (t_struct *)malloc(sizeof(t_struct));
	op = (t_oper *)malloc(sizeof(t_oper));
	head_a->next = NULL;
	head_b->next = NULL;
	op->next = NULL;
	init_stack(head_a, argc, argv);
	if (error_check_after(head_a))
		return (write_error());
	push_swap(head_a, head_b, op);
	handle_operation_list(op);
	handle_free(head_a, head_b, op);
	return (0);
}
