/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <hmyoung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:13:03 by hmyoung           #+#    #+#             */
/*   Updated: 2021/07/09 12:13:07 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./get_next_line.h"

typedef struct s_struct
{
	int				value;
	struct s_struct	*next;
}					t_struct;
typedef struct s_oper
{
	char			*operation;
	struct s_oper	*next;
}					t_oper;
long long	ft_atoi(const char *str);
char		*ft_strdup(const char *s);
size_t		ft_strlen(const char *s);
void		add_lst_back(t_struct *node, int n);
t_struct	*find_lst_last(t_struct *node);
int			size_of_list(t_struct *list);
void		add_op_list(t_oper *op, char *str);
t_oper		*find_op_last(t_oper *node);
void		handle_operation_list(t_oper *op);
int			error_check_before(int argc, char **argv);
int			error_check_after(t_struct *head);
int			write_error(void);
void		pa(t_struct *head_a, t_struct *head_b, t_oper *op);
void		pb(t_struct *head_a, t_struct *head_b, t_oper *op);
void		sa(t_struct *head_a, t_oper *op);
void		sb(t_struct	*head_b, t_oper *op);
void		ss(t_struct *head_a, t_struct *head_b, t_oper *op);
void		ra(t_struct *head_a, t_oper *op);
void		rb(t_struct	*head_b, t_oper *op);
void		rr(t_struct *head_a, t_struct *head_b, t_oper *op);
void		rra(t_struct *head_a, t_oper *op);
void		rrb(t_struct *head_b, t_oper *op);
void		rrr(t_struct *head_a, t_struct *head_b, t_oper *op);
void		a_to_b(t_struct *head_a, t_struct *head_b, int n, t_oper *op);
void		b_to_a(t_struct *head_a, t_struct *head_b, int n, t_oper *op);
int			check_pivot(t_struct *node, int len);
void		quick_sort(int *arr, int start, int end);
int			get_partition(int *arr, int start, int end);
int			*fill_arr(t_struct *node, int *arr, int len);
void		call_ra(t_struct *head_a, int *ra_cnt, t_oper *op);
void		call_rb(t_struct *head_b, int *rb_cnt, t_oper *op);
void		call_pa(t_struct *head_a, t_struct *head_b, int *cnt, t_oper *op);
void		call_pb(t_struct *head_a, t_struct *head_b, int *cnt, t_oper *op);
void		handle_free(t_struct *head_a, t_struct *head_b, t_oper *op);
void		sort_two_a(t_struct *head_a, t_oper *op);
void		sort_two_b(t_struct *head_b, t_oper *op);
void		sort_three_a(t_struct *head_a, t_oper *op);
void		sort_three_b(t_struct *head_b, t_oper *op);
void		sort_five(t_struct *head_a, t_struct *head_b, int len, t_oper *op);
int			find_max(t_struct *head);
int			find_min(t_struct *head);
long long	ft_atoi(const char *str);
char		*ft_strdup(const char *s);
size_t		ft_strlen(const char *s);
void		add_lst_back(t_struct *node, int n);
t_struct	*find_lst_last(t_struct *node);
int			size_of_list(t_struct *list);
void		add_op_list(t_oper *op, char *str);
t_oper		*find_op_last(t_oper *node);
void		handle_operation_list(t_oper *op);
int			error_check_before(int argc, char **argv);
int			error_check_after(t_struct *head);
int			write_error(void);
void		pa(t_struct *head_a, t_struct *head_b, t_oper *op);
void		pb(t_struct *head_a, t_struct *head_b, t_oper *op);
void		sa(t_struct *head_a, t_oper *op);
void		sb(t_struct	*head_b, t_oper *op);
void		ss(t_struct *head_a, t_struct *head_b, t_oper *op);
void		ra(t_struct *head_a, t_oper *op);
void		rb(t_struct	*head_b, t_oper *op);
void		rr(t_struct *head_a, t_struct *head_b, t_oper *op);
void		rra(t_struct *head_a, t_oper *op);
void		rrb(t_struct *head_b, t_oper *op);
void		rrr(t_struct *head_a, t_struct *head_b, t_oper *op);
void		a_to_b(t_struct *head_a, t_struct *head_b, int n, t_oper *op);
void		b_to_a(t_struct *head_a, t_struct *head_b, int n, t_oper *op);
int			check_pivot(t_struct *node, int len);
void		quick_sort(int *arr, int start, int end);
int			get_partition(int *arr, int start, int end);
int			*fill_arr(t_struct *node, int *arr, int len);
void		call_ra(t_struct *head_a, int *ra_cnt, t_oper *op);
void		call_rb(t_struct *head_b, int *rb_cnt, t_oper *op);
void		call_pa(t_struct *head_a, t_struct *head_b, int *cnt, t_oper *op);
void		call_pb(t_struct *head_a, t_struct *head_b, int *cnt, t_oper *op);
void		handle_free(t_struct *head_a, t_struct *head_b, t_oper *op);
void		sort_two_a(t_struct *head_a, t_oper *op);
void		sort_two_b(t_struct *head_b, t_oper *op);
void		sort_three_a(t_struct *head_a, t_oper *op);
void		sort_three_b(t_struct *head_b, t_oper *op);
void		sort_five(t_struct *head_a, t_struct *head_b, int len, t_oper *op);
int			find_max(t_struct *head);
int			find_min(t_struct *head);
int			ft_strcmp(char *s1, char *s2);
int			return_merge_case(t_oper *op);
int			return_delete_case(t_oper *op);
void		print_op_list(t_oper *op);
t_oper		*create_op_list_node(char *oper);
void		delete_op_list_in_middle(t_oper *op, int num);
void		add_op_list_in_middle(t_oper *op, t_oper *node, int num);
int			merge_operation(t_oper *op);
int			delete_operation(t_oper *op);
void		optimize_operation(t_oper *op);
void		handle_operation_list(t_oper *op);
int			already_sort(t_struct *head);
void		init_stack(t_struct *head_a, int argc, char **argv);
void		free_stack(t_struct *node);
void		merge_by_case(t_oper *op, int index, int merge_case);
int			r_check(t_oper	*temp);
#endif
