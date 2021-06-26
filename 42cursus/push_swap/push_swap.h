/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <hmyoung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 13:27:35 by hmyoung           #+#    #+#             */
/*   Updated: 2021/06/18 13:27:38 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_node {
	int value;
	struct s_node *prev;
	struct s_node *next;
} t_node;

int					ft_atoi(const char *str);
int					ft_isspace(char str);
t_node				*create_node(int value);
t_node 				**create_head();
void add_front(t_node **head, char **av, int ac);
void push_function(t_node **a, t_node **b);
void swap_stack(t_node **node);
void swap_all(t_node **a, t_node **b);
void from_top_to_bot(t_node **node);
void from_top_to_bot_all(t_node **a, t_node **b);
void from_bot_to_top(t_node **node);
void from_bot_to_top_all(t_node **a, t_node **b);
int		get_partition(int *sort, int start, int end);
void	quick_sort(int *sort, int start, int end);
void a_to_b(t_node **head_a, t_node **head_b, int r);
void b_to_a(t_node **head_a, t_node **head_b, int r);
int select_pivot(t_node **head);


#endif

