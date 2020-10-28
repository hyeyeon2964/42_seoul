/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:07:43 by hmyoung           #+#    #+#             */
/*   Updated: 2020/10/28 20:50:56 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *des, const void *src, size_t num)
{
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char*)des;
	s = (unsigned char*)src;
	if (d == s || num == 0)
		return (des);
	if (s < d)
	{
		while (num--)
			*(d + num) = *(s + num);
	}
	else
	{
		ft_memcpy(des, src, num);
	}
	return (des);
}
