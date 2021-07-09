/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <hmyoung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:39:36 by hmyoung           #+#    #+#             */
/*   Updated: 2021/07/09 12:39:38 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stack(t_struct *head_a, int argc, char **argv)
{
	int			i;
	int			n;

	i = 1;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		add_lst_back(head_a, n);
		i++;
	}
}
