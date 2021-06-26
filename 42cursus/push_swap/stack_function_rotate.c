#include "push_swap.h"

void from_top_to_bot(t_node **node) { //첫 번째 원소가 마지막으로
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

void from_bot_to_top(t_node **node) { //마지막 원소가 첫번째로
	t_node *temp_second;
	t_node *temp_last;
	t_node **temp_head;
	t_node *head;


	head = (*node);
	temp_head = node;
	//탐색할 노드가 1개 일 때 오류 처리 안됨

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
