/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <hmyoung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:14:11 by hmyoung           #+#    #+#             */
/*   Updated: 2021/07/09 12:14:13 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_oper	*create_op_list_node(char *oper)
{
	t_oper		*res;

	res = (t_oper *)malloc(sizeof(t_oper));
	res->operation = ft_strdup(oper);
	res->next = NULL;
	return (res);
}

void	delete_op_list_in_middle(t_oper *op, int num)
{
	t_oper		*temp;
	t_oper		*temp_op_node;
	int			index;

	index = 1;
	temp = op->next;
	if (num == 1)
	{
		op->next = op->next->next;
		free(temp->operation);
		free(temp);
		return ;
	}
	num = num - 2;
	while (num--)
		temp = temp->next;
	temp_op_node = temp->next;
	temp->next = temp_op_node->next;
	free(temp_op_node->operation);
	free(temp_op_node);
}

void	add_op_list_in_middle(t_oper *op, t_oper *node, int num)
{
	t_oper		*temp;
	t_oper		*temp_op_node;
	int			index;

	index = 1;
	temp = op->next;
	if (num == 1)
	{
		temp = node;
		return ;
	}
	while (temp != NULL && index < num - 1)
	{
		temp = temp->next;
		index++;
	}
	temp_op_node = temp->next;
	temp->next = node;
	node->next = temp_op_node;
}

int	r_check(t_oper	*temp)
{
	if (ft_strcmp(temp->operation, "ra")
		&& ft_strcmp(temp->next->operation, "rra"))
		return (1);
	if (ft_strcmp(temp->operation, "rra")
		&& ft_strcmp(temp->next->operation, "ra"))
		return (1);
	if (ft_strcmp(temp->operation, "rb")
		&& ft_strcmp(temp->next->operation, "rrb"))
		return (1);
	if (ft_strcmp(temp->operation, "rrb")
		&& ft_strcmp(temp->next->operation, "rb"))
		return (1);
	if (ft_strcmp(temp->operation, "rr")
		&& ft_strcmp(temp->next->operation, "rrr"))
		return (1);
	if (ft_strcmp(temp->operation, "rrr")
		&& ft_strcmp(temp->next->operation, "rr"))
		return (1);
	return (0);
}
