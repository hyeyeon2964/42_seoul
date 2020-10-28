/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:54:11 by hmyoung           #+#    #+#             */
/*   Updated: 2020/10/28 20:13:39 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *des, const void *src, int c, size_t num)
{
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char *)des;
	s = (unsigned char *)src;
	while (num--)
	{
		*d = *s;
		if (*s == (unsigned char)c)
		{
			return (d + 1);
		}
		d++;
		s++;
	}
	return (NULL);
}
