/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <hmyoung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 13:27:48 by hmyoung           #+#    #+#             */
/*   Updated: 2021/06/18 13:27:50 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *create_node(int value)
{
	t_node *temp;

	if(!(temp = (t_node *)malloc(sizeof(t_node))))
		return(0);
	temp->value = value;
	temp->next = NULL;

	return (temp);
}

t_node **create_head()
{
	t_node **head;

	if(!(head = (t_node **)malloc(sizeof(t_node *))))
		return(0);

	return (head);
}
