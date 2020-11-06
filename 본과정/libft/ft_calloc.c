/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:41:28 by hmyoung           #+#    #+#             */
/*   Updated: 2020/11/06 17:04:26 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*result;
	size_t	total_size;
	size_t	i;

	total_size = count * size;
	if (!(result = (void *)malloc(total_size)))
		return (0);
	i = 0;
	while (i < total_size)
	{
		result[i++] = 0;
	}
	return (result);
}
