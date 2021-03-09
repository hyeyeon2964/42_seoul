/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:38:49 by hmyoung           #+#    #+#             */
/*   Updated: 2020/10/30 17:03:04 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int character)
{
	while (*str)
	{
		if (*str == character)
			return ((char *)str);
		str++;
	}
	if (*str == character)
		return ((char *)str);
	return (NULL);
}
