/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 10:23:52 by jung-lee          #+#    #+#             */
/*   Updated: 2021/07/01 12:40:54 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_oper			*find_op_last(t_oper *node)
{
	t_oper		*temp;

	temp = node;
	if (!temp)
		return (NULL);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void			add_op_list(t_oper *op, char *operation)
{
	t_oper		*new;
	t_oper		*temp;

	new = (t_oper *)malloc(sizeof(t_oper));
	temp = find_op_last(op);
	temp->next = new;
	new->operation = ft_strdup(operation);
	new->next = NULL;
}
