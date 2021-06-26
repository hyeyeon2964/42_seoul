#include "push_swap.h"

void push_function(t_node **a, t_node **b) // b의 첫번째 값을 a의 맨 위에 옮기기
{
	t_node *temp;

	temp = (*b)->next;
	(*b)->next = *a;
	(*a) = (*b);
	(*b) = temp;
}

void swap_stack(t_node **node) // 첫번째 원소와 두번째 원소 바꿈
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
