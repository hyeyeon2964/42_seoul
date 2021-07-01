#include "../includes/push_swap.h"

int find_max(t_struct *head)
{
	int max;
	t_struct *temp;

	temp = head->next;
	max = temp->value;
	while (temp != NULL)
	{
		if (max < temp->value)
			max = temp->value;
		temp = temp->next;
	}
	return (max);
}

int find_min(t_struct *head)
{
	int min;
	t_struct *temp;
	temp = head->next;
	min = temp->value;
	while (temp != NULL)
	{
		if (min > temp->value)
			min = temp->value;
		temp = temp->next;
	}
	return (min);
}

void sort_two_a(t_struct *head_a, t_oper *op)
{
	t_struct *temp_up;
	t_struct *temp_down;

	temp_up = head_a->next;
	temp_down = temp_up->next;

	if (temp_up->value > temp_down->value)
		sa(head_a, op);
}

void sort_two_b(t_struct *head_b, t_oper *op)
{
	t_struct *temp_up;
	t_struct *temp_down;

	temp_up = head_b->next;
	temp_down = temp_up->next;

	if (temp_up->value < temp_down->value)
		sa(head_b, op);
}

void sort_three_a(t_struct *head_a, t_oper *op)
{
	int max;
	t_struct *temp;

	temp = head_a->next;
	max = find_max(head_a);
	while (max != temp->value)
		temp = temp->next;
	//최대값이 마지막에 있을 때
	if (temp->next == NULL)
		sort_two_a(head_a, op);
	//최대값이 두 번째에 있을 때
	else if (temp->next->next == NULL)
	{
		rra(head_a, op);
		sort_two_a(head_a, op);
	}
	//최대값이 제일 위에 있을 때
	else
	{
		ra(head_a, op);
		sort_two_a(head_a, op);
	}
}

void sort_three_b(t_struct *head_b, t_oper *op)
{
	int min;
	t_struct *temp;
	temp = head_b->next;
	min = find_min(head_b);
	while (min != temp->value)
		temp = temp->next;
	if (temp->next == NULL)
		sort_two_b(head_b, op);
	else if (temp->next->next == NULL)
	{
		rrb(head_b, op);
		sort_two_b(head_b, op);
	}
	else
	{
		rb(head_b, op);
		sort_two_b(head_b, op);
	}
}

//먼가 꼬임.........
void sort_six(t_struct *head_a, t_struct *head_b, t_oper *op, int len)
{
	int middle;
	t_struct *temp;

	temp = head_a->next;
	middle = check_pivot(head_a, len);
	printf("middle: ㅇㄴㅇㄴㅇㄴ%d\n\n", middle);
	printf("middle: ㅇㄴㅇㄴㅇㄴ%d\n\n", middle);
	printf("pb: %d", middle);
	while (temp != NULL)
	{
		printf("pb: %d", temp->value);

		if (temp->value <= middle)
		{
			pb(head_a, head_b, op);
			printf("pb: %d", temp->value);
		}
		else
			ra(head_a, op);
		temp = temp->next;
	}

	// t_struct *temp1 = head_a->next;
	// while (temp1 != NULL)
	// {
	// 	printf("temp 1: %d \n", temp1->value);
	// 	temp1 = temp1->next;
	// }

	int i;
	i = middle;

	while (middle)
	{
		rra(head_a, op);
		middle--;
	}
	sort_three_a(head_a, op);
	handle_operation_list(op);
	sort_three_b(head_b, op);
	while (i)
	{
		pa(head_a, head_b, op);
		i--;
	}
}
