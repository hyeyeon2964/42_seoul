/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <hmyoung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 13:26:07 by hmyoung           #+#    #+#             */
/*   Updated: 2021/06/18 13:26:17 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	add_front(t_node **head, t_node *temp)
{
	temp->next = (*head);
	*head = temp;
}

void push_front_from_back(t_node **a, t_node **b)
{
	t_node *temp;

	temp = (*b)->next;
	(*b)->next = *a;
	(*a) = (*b);
	(*b) = temp;
}

void swap_stack(t_node **node)
{
	int temp;
	temp = (*node)->next->value;
	(*node)->next->value = (*node)->value;
	(*node)->value = temp;
}

void swap_all(t_node **a, t_node **b)
{
	swap_stack(a);
	swap_stack(b);
}

void from_top_to_bot(t_node **node) {
	t_node *temp_second;
	t_node *temp_last;
	t_node **temp_head;
	t_node *head;

	head = (*node);
	temp_head = node;
	temp_second = (*node)->next;
	while ((*temp_head)->next != NULL)
	{
		(*temp_head) = (*temp_head)->next;
	}
	temp_last = (*temp_head);
	temp_last->next = head;
	head->next = NULL;
	(*node) = temp_second;
}

void from_top_to_bot_all(t_node **a, t_node **b)
{
	from_top_to_bot(a);
	from_top_to_bot(b);
}

void from_bot_to_top(t_node **node) {
	t_node *temp_second;
	t_node *temp_last;
	t_node **temp_head;
	t_node *head;

	head = (*node);
	temp_head = node;
	//temp_second = (*node)->next;
	while ((*temp_head)->next->next != NULL)
	{
		(*temp_head) = (*temp_head)->next;
	}
	temp_second = (*temp_head);
	temp_last = temp_second->next;
	temp_second->next = NULL;
	temp_last->next = head;
	(*node) = temp_last;
}

void from_bot_to_top_all(t_node **a, t_node **b)
{
	from_bot_to_top(a);
	from_bot_to_top(b);
}

int main(int ac, char **av)
{
	t_node *a;
	t_node *b;
	t_node *temp;
	t_node **head_a;
	t_node **head_b;
	int index;

	index = ac - 1;
	if(ac < 2)
		return (0);

	if(!(a = (t_node *)malloc(sizeof(t_node))))
		return(0);
	a = create_node(ft_atoi(av[index--]));
	head_a = &a;
	while (index != 0)
	{
		temp = create_node(ft_atoi(av[index]));
		add_front(head_a, temp);
		index--;
	}

	if(!(b = (t_node *)malloc(sizeof(t_node))))
		return(0);

	b = create_node(1);
	head_b = &b;

	add_front(head_b, create_node(3));
	add_front(head_b, create_node(5));
	add_front(head_b, create_node(7));
	//push_front_from_back(head_a, head_b);
	//swap_stack(head_a);
	from_bot_to_top_all(head_a, head_b);
	while ((*head_a) != NULL)
	{
		printf("%d \n", (*head_a)->value);
		(*head_a) = (*head_a)->next;
	}
	printf("\n \n \n");
	while ((*head_b) != NULL)
	{
		printf("%d \n", (*head_b)->value);
		(*head_b) = (*head_b)->next;
	}
}
