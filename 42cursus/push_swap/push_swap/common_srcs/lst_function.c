/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <hmyoung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:39:46 by hmyoung           #+#    #+#             */
/*   Updated: 2021/07/09 12:39:48 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_struct	*find_lst_last(t_struct *node)
{
	t_struct	*temp;

	temp = node;
	if (!temp)
		return (NULL);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	add_lst_back(t_struct *node, int n)
{
	t_struct	*new;
	t_struct	*temp;

	new = (t_struct *)malloc(sizeof(t_struct));
	temp = find_lst_last(node);
	temp->next = new;
	new->value = n;
	new->next = NULL;
}

int	size_of_list(t_struct *list)
{
	int			n;
	t_struct	*temp;

	n = 0;
	temp = list->next;
	while (temp != NULL)
	{
		n++;
		temp = temp->next;
	}
	return (n);
}

t_oper	*find_op_last(t_oper *node)
{
	t_oper		*temp;

	temp = node;
	if (!temp)
		return (NULL);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	add_op_list(t_oper *op, char *operation)
{
	t_oper		*new;
	t_oper		*temp;

	new = (t_oper *)malloc(sizeof(t_oper));
	temp = find_op_last(op);
	temp->next = new;
	new->operation = ft_strdup(operation);
	new->next = NULL;
}
