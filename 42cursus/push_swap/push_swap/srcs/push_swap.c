/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:28:44 by jung-lee          #+#    #+#             */
/*   Updated: 2021/07/01 13:46:08 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			init_stack(t_struct *head_a, int argc, char **argv)
{
	int			i;
	int			n;

	i = 1;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		add_lst_back(head_a, n);
		i++;
	}
}

void			push_swap(t_struct *head_a, t_struct *head_b, t_oper *op)
{
	int			n;

	n = size_of_list(head_a);
	if (n == 2)
		sort_two_a(head_a, op);
	else if (n == 3)
		sort_three_a(head_a, op);
	else if (n == 6)
		sort_six(head_a, head_b, op, n);
	else
		a_to_b(head_a, head_b, n, op);
}

int				main(int argc, char **argv)
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
