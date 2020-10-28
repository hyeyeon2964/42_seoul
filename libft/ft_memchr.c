/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:52:01 by hmyoung           #+#    #+#             */
/*   Updated: 2020/10/28 21:03:12 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *ptr, int value, size_t num)
{
	unsigned char *p;

	p = (unsigned char *)ptr;
	while (num--)
	{
		if (*p == (unsigned char)value)
		{
			return (p);
		}
		p++;
	}
	return (0);
}
