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

#endif

