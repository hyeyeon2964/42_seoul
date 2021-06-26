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

void print_stack(t_node **head)
{
	t_node *temp;
	temp = (*head);

	while (temp != NULL)
	{
		printf("%d  ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

int *get_node_to_arr(int len, t_node **head)
{
	int index;
	int *arr;
	t_node *temp;

	index = 0;
	temp = (*head);
	if (!(arr = (int *)malloc(sizeof(int) * len)))
		return (NULL);

	while (temp != NULL)
	{
		arr[index] = temp->value;
		temp = temp->next;
		index++;
	}
	return (arr);
}
int get_length(t_node **head)
{
    int length;
    t_node *temp;

    temp = (*head);
    length = 0;

    while(temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return (length);
}
int select_pivot(t_node **head)
{
	int index;
    int len;
	int result;
	int *arr;
	t_node *temp;

	temp = (*head);
	index = 0;
	result = 0;
    len = get_length(head);
	arr = get_node_to_arr(len, head);
	quick_sort(arr, 0,  len - 1);
    result = arr[len / 2];
	if (len % 2 == 0) {
        result = arr[(len / 2) -1];
    }
	return (result);
}

int main(int ac, char **av)
{
	t_node *a;
	t_node *b;
	t_node **head_a;
	t_node **head_b;

	if(ac < 2)
		return (0);

	if(!(a = (t_node *)malloc(sizeof(t_node))))
		return(0);
	a = create_node(ft_atoi(av[ac - 1]));
	head_a = &a;
	add_front(head_a, av, ac-1);
	if(!(b = (t_node *)malloc(sizeof(t_node))))
		return(0);
	//b = create_node(1);
	head_b = &b;
	//A_to_B(head_a, head_b, ac-1);
	//print_stack(head_a);
	//printf("\n\n\n\n\n");
	a_to_b(head_a, head_b, ac - 1);
	print_stack(head_a);

}
