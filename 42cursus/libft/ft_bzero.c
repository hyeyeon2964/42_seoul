/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 19:47:33 by hmyoung           #+#    #+#             */
/*   Updated: 2020/10/28 19:26:55 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_bzero(void *ptr, size_t num)
{
	unsigned char		*start_ptr;
	size_t				index;

	index = 0;
	start_ptr = (unsigned char *)ptr;
	while (index != num)
	{
		*start_ptr++ = 0;
		index++;
	}
	return (ptr);
}
