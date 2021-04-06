/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 15:21:52 by hmyoung           #+#    #+#             */
/*   Updated: 2020/10/28 19:22:56 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char		*start_ptr;

	start_ptr = (unsigned char *)ptr;
	while (num--)
	{
		*start_ptr++ = (unsigned char)value;
	}
	return (ptr);
}
