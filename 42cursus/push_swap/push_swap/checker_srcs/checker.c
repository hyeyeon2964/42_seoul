/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <hmyoung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:26:21 by hmyoung           #+#    #+#             */
/*   Updated: 2021/07/09 12:26:23 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	select_function(char *input, t_struct *head_a,
t_struct *head_b, t_oper *op)
{
	if (ft_strcmp(input, "pa"))
		pa(head_a, head_b, op);
	else if (ft_strcmp(input, "pb"))
		pb(head_a, head_b, op);
	else if (ft_strcmp(input, "sa"))
		sa(head_a, op);
	else if (ft_strcmp(input, "sb"))
		sb(head_b, op);
	else if (ft_strcmp(input, "ss"))
		ss(head_a, head_b, op);
	else if (ft_strcmp(input, "ra"))
		ra(head_a, op);
	else if (ft_strcmp(input, "rb"))
		rb(head_b, op);
	else if (ft_strcmp(input, "rr"))
		rr(head_a, head_b, op);
	else if (ft_strcmp(input, "rra"))
		rra(head_a, op);
	else if (ft_strcmp(input, "rrb"))
		rrb(head_b, op);
	else if (ft_strcmp(input, "rrr"))
		rrr(head_a, head_b, op);
}

void	malloc_stack(t_struct **head_a, t_struct **head_b, t_oper **op)
{
	*head_a = (t_struct *)malloc(sizeof(t_struct));
	*head_b = (t_struct *)malloc(sizeof(t_struct));
	*op = (t_oper *)malloc(sizeof(t_oper));
	(*head_a)->next = NULL;
	(*head_b)->next = NULL;
	(*op)->next = NULL;
}

void	free_all(t_struct *head_a, t_struct *head_b)
{
	free_stack(head_a);
	free_stack(head_b);
}

void	print_result(t_struct *head_a)
{
	if (already_sort(head_a))
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	char				*oper;
	t_struct			*head_a;
	t_struct			*head_b;
	t_oper				*op;

	if (error_check_before(argc, argv))
		return (write_error());
	malloc_stack(&head_a, &head_b, &op);
	init_stack(head_a, argc, argv);
	if (error_check_after(head_a))
		return (write_error());
	while (get_next_line(0, &oper) > 0)
	{
		select_function(oper, head_a, head_b, op);
		free(oper);
	}
	select_function(oper, head_a, head_b, op);
	free(oper);
	print_result(head_a);
	free_all(head_a, head_b);
	return (0);
}
