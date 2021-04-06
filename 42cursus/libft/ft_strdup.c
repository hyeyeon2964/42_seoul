/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:04:39 by hmyoung           #+#    #+#             */
/*   Updated: 2020/11/06 20:02:48 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	s_size;
	size_t	index;

	s_size = ft_strlen(s);
	if (!(result = (void *)malloc(s_size + 1)))
		return (0);
	index = 0;
	while (index < s_size)
	{
		result[index] = s[index];
		index++;
	}
	result[index] = '\0';
	return (result);
}
