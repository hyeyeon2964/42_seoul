/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_operation_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:33:24 by jung-lee          #+#    #+#             */
/*   Updated: 2021/07/01 17:19:22 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			handle_operation_list(t_oper *op)
{
	t_oper		*temp;
	size_t		len;

	temp = op->next;
	// operation list 최적화 함수
	// 최적화된 리스트 출력
	while (temp != NULL)
	{
		len = ft_strlen(temp->operation);
		if (len == 2)
			write(1, temp->operation, 2);
		else
			write(1, temp->operation, 3);
		write(1, "\n", 1);
		temp = temp->next;
	}
}
