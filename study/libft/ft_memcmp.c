/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:04:29 by hmyoung           #+#    #+#             */
/*   Updated: 2020/10/28 21:45:43 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned char *p1;
	unsigned char *p2;

	p1 = (unsigned char *)ptr1;
	p2 = (unsigned char *)ptr2;
	while (num--)
	{
		if (*p1 != *p2)
		{
			return ((int)*p1 - *p2);
		}
		p1++;
		p2++;
	}
	return (0);
}
