#include "push_swap.h"
#include <stdio.h>
void	swap_sa(t_node a, t_node b)
{

}
void	create_stack(t_node *a, char **av)
{
	t_node *temp;
	int i;

	i = 0;
	if(!(temp = (t_node *)malloc(sizeof(t_node))))
		return(0);
	while (av[i] != '\0')
	{
		temp->next = (t_node *)malloc(sizeof(t_node));
		temp->value = ft_atoi(*av[i]);
	}
}

int main(int ac, char **av)
{
	t_node a;
	t_node b;

	if(ac < 2)
		return (0);

}
