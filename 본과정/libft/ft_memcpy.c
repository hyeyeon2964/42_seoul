/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:40:52 by hmyoung           #+#    #+#             */
/*   Updated: 2020/10/28 19:29:13 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *des, const void *src, size_t num)
{
	unsigned char *tmp;
	unsigned char *s;

	tmp = (unsigned char *)des;
	s = (unsigned char *)src;
	while (num--)
	{
		*tmp++ = *s++;
	}
	return (des);
}
