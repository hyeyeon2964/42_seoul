/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <hmyoung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:16:27 by hmyoung           #+#    #+#             */
/*   Updated: 2021/07/09 12:16:28 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	merge_by_case(t_oper *op, int index, int merge_case)
{
	t_oper		*added_node;

	delete_op_list_in_middle(op, index);
	delete_op_list_in_middle(op, index);
	if (merge_case == 1)
		added_node = create_op_list_node("rr");
	if (merge_case == 2)
		added_node = create_op_list_node("ss");
	if (merge_case == 3)
		added_node = create_op_list_node("rrr");
	add_op_list_in_middle(op, added_node, index);
}

int	merge_operation(t_oper *op)
{
	int			merge_case;
	int			index;
	t_oper		*temp;

	index = 1;
	temp = op->next;
	while (temp->next != NULL)
	{
		merge_case = return_merge_case(temp);
		if (merge_case)
		{
			merge_by_case(op, index, merge_case);
			return (1);
		}
		else
			temp = temp->next;
		index++;
	}
	return (0);
}

int	delete_operation(t_oper *op)
{
	t_oper		*temp;
	int			index;

	temp = op->next;
	index = 1;
	while (temp->next != NULL)
	{
		if (return_delete_case(temp))
		{
			temp = temp->next->next;
			delete_op_list_in_middle(op, index);
			delete_op_list_in_middle(op, index);
			return (1);
		}
		else
		{
			temp = temp->next;
			index++;
		}
	}
	return (0);
}

int	return_merge_case(t_oper *op)
{
	t_oper		*temp;

	temp = op;
	if (ft_strcmp(temp->operation, "ra")
		&& ft_strcmp(temp->next->operation, "rb"))
		return (1);
	if (ft_strcmp(temp->operation, "rb")
		&& ft_strcmp(temp->next->operation, "ra"))
		return (1);
	if (ft_strcmp(temp->operation, "sa")
		&& ft_strcmp(temp->next->operation, "sb"))
		return (2);
	if (ft_strcmp(temp->operation, "sb")
		&& ft_strcmp(temp->next->operation, "sa"))
		return (2);
	if (ft_strcmp(temp->operation, "rra")
		&& ft_strcmp(temp->next->operation, "rrb"))
		return (3);
	if (ft_strcmp(temp->operation, "rrb")
		&& ft_strcmp(temp->next->operation, "rra"))
		return (3);
	return (0);
}

int	return_delete_case(t_oper *op)
{
	t_oper		*temp;

	temp = op;
	if (ft_strcmp(temp->operation, "pa")
		&& ft_strcmp(temp->next->operation, "pb"))
		return (1);
	if (ft_strcmp(temp->operation, "pb")
		&& ft_strcmp(temp->next->operation, "pa"))
		return (1);
	if (ft_strcmp(temp->operation, "sa")
		&& ft_strcmp(temp->next->operation, "sa"))
		return (1);
	if (ft_strcmp(temp->operation, "sb")
		&& ft_strcmp(temp->next->operation, "sb"))
		return (1);
	if (r_check(op))
		return (1);
	return (0);
}
