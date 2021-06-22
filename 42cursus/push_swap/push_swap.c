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
void            A_to_B(t_node **head_a, t_node **head_b, int n);
int select_pivot(t_node **head, int length);
void            B_to_A(t_node **head_a, t_node **head_b, int n)
{
    int         rb_cnt;
    int         pa_cnt;
    int         temp;
    rb_cnt = 0;
    pa_cnt = 0;
    if (n == 1)
    {
        push_front_from_back(head_a, head_b);
        return ;
    }
    while (n)
    {
        if ((*head_b)->value > select_pivot(head_b, n))
        {
            from_top_to_bot(head_b);
            rb_cnt++;
        }
        else
        {
            push_front_from_back(head_a, head_b);
            pa_cnt++;
        }
        n--;
    }
    temp = rb_cnt;
    while (temp)
    {
        from_bot_to_top(head_b);
        temp--;
    }
    A_to_B(head_a, head_b, pa_cnt);
    B_to_A(head_a, head_b, rb_cnt);
}
void            A_to_B(t_node **head_a, t_node **head_b, int n)
{
    int         ra_cnt;
    int         pb_cnt;
    int         temp;
    ra_cnt = 0;
    pb_cnt = 0;
    if (n == 1)
        return ;
    // pivot 선택
	int pivot;
	pivot = select_pivot(head_a, n);
    while (n)
    {
        if ((*head_a)->value > pivot)
        {
            from_top_to_bot(head_a);
            ra_cnt++;
        }
        else
        {
            push_front_from_back(head_b, head_a);
            pb_cnt++;
        }
        n--;
    }
    temp = ra_cnt;
    while (temp)
    {
        from_bot_to_top(head_a);
        temp--;
    }
    A_to_B(head_a, head_b, ra_cnt);
    B_to_A(head_a, head_b, pb_cnt);
}

void print_stack(t_node **head)
{
	t_node *temp;
	temp = (*head);

	while (temp != NULL)
	{
		printf("%d \n", temp->value);
		temp = temp->next;
	}
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
int select_pivot(t_node **head, int length)
{
	int index;
	int result;
	int *arr;
	t_node *temp;

	temp = (*head);
	index = 0;
	result = 0;

	arr = get_node_to_arr(length, head);
	quick_sort(arr, 0,  length - 1);
	result = arr[length / 2];

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
	b = create_node(1);
	head_b = &b;
	A_to_B(head_a, head_b, ac-1);
	print_stack(head_a);
}
