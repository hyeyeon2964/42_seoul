#include "push_swap.h"
#include <stdio.h>
void	swap_sa(Node a, Node b)
{

}

int main(void)
{
	Head *head = malloc(sizeof(Head));

	Node *node1 = malloc(sizeof(Node));
	head->top = node1;
	node1->value = 10;

	Node *node2 = malloc(sizeof(Node));
	node1->next = node2;
	node2->value = 5;
	node2->next = NULL;

	printf("Node 1: %d  Node2: %d size: %d \n", node1->value, node2->value, head->size);
}
