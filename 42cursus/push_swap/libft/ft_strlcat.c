/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:49:46 by hmyoung           #+#    #+#             */
/*   Updated: 2020/11/06 13:14:22 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = dest_len;
	j = 0;
	if (size <= dest_len)
		return (src_len + size);
	while (src[j] != '\0' && i + 1 < size)
	{
		dest[i++] = src[j++];
	}
	dest[i] = '\0';
	return (src_len + dest_len);
}
