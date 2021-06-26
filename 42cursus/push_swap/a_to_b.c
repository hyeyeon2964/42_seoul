#include "push_swap.h"

void a_to_b(t_node **head_a, t_node **head_b, int r)
{
	int ra_cnt;
	int pb_cnt;
	int pivot;
	int temp;
	t_node *temp_a;
	t_node *temp_b;

	temp_a = (*head_a);
	temp_b = (*head_b);
	ra_cnt = 0;
	pb_cnt = 0;
	if (r == 1)
		return ;
	pivot = select_pivot(head_a);
	while(r--)
	{
		if ((*head_a)->value > pivot)
		{
			from_top_to_bot(head_a);
			ra_cnt++;
		}
		else
		{
			push_function(head_b, head_a);
			pb_cnt++;
		}
	}
	temp = ra_cnt;
	while(temp--)
		from_bot_to_top(head_a);
	a_to_b(head_a, head_b, ra_cnt);
	b_to_a(head_a, head_b, pb_cnt);
}

void b_to_a(t_node **head_a, t_node **head_b, int r)
{
	int rb_cnt;
	int pa_cnt;
	int temp;
	int pivot;
	t_node *temp_a;
	t_node *temp_b;

	temp_a = (*head_a);
	temp_b = (*head_b);

	rb_cnt = 0;
	pa_cnt = 0;
	if (r == 1)
	{
		push_function(head_a, head_b);
		return ;
	}
	pivot = select_pivot(head_a);
	while (r --)
	{
		if ((*head_b)->value <= pivot)
		{
			from_top_to_bot(head_b);
			rb_cnt++;
		}
		else
		{
			push_function(head_a, head_b);
			pa_cnt++;
		}
	}
	temp = rb_cnt;
	while (temp)
	{
		from_bot_to_top(head_b);
	}
}
