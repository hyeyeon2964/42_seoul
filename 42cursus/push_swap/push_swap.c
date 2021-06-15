#include "push_swap.h"
#include "utils.h"
#include <stdio.h>

int		ft_isspace(char str)
{
	if ((9 <= str && str <= 13) || str == 32)
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	int		sign;
	int		i;
	long	result;

	i = 0;
	while (ft_isspace(str[i]) == 1)
	{
		i++;
	}
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		if (result > 2147483647 && sign == 1)
			return (-1);
		if (result > 2147483648 && sign == -1)
			return (0);
		i++;
	}
	return (sign * result);
}

void print_stack(t_node *st)
{
	printf("%d \n", 5555);
	while(st->next != NULL)
	{
		printf("%d \n", st->value);
		st = st->next;
	}
}

int	create_stack(t_node *a, char **av, int ac)
{
	t_node *temp;
	int i;

	i = ac - 1;
	if(!(temp = (t_node *)malloc(sizeof(t_node))))
		return(0);
	while (i > 0)
	{
		temp->next = (t_node *)malloc(sizeof(t_node));
		temp->value = ft_atoi(av[i]);
		if (i == ac - 1)
			temp->next = NULL;
		else {
			temp->next = a;
		}
		i--;
	}
	print_stack(a);
	return (0);
}

int main(int ac, char **av)
{
	t_node *a;
	t_node *b;

	if(!(a = (t_node *)malloc(sizeof(t_node))))
		return(0);
	if(ac < 2)
		return (0);
	create_stack(a, av, ac);

}
