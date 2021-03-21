/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <hmyoung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:26:28 by hmyoung           #+#    #+#             */
/*   Updated: 2021/03/21 21:08:38 by hmyoung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t len;
	size_t index;

	index = 0;
	len = 0;

	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	s_size;
	size_t	index;

	s_size = ft_strlen(s);
	if (!(result = (void *)malloc(s_size + 1)))
		return (0);
	index = 0;
	while (s[index])
	{
		result[index] = s[index];
		index++;
	}
	result[index] = '\0';
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	s1_size;

	if (s1 && s2)
	{
		s1_size = ft_strlen(s1);
		if (!(result = (char *)malloc(s1_size + ft_strlen(s2) + 1)))
			return (0);
		i = 0;
		while (s1[i] != '\0')
		{
			result[i] = s1[i];
			i++;
		}
		i = 0;
		while (s2[i] != '\0')
		{
			result[s1_size++] = s2[i++];
		}
		result[s1_size] = '\0';
		return (result);
	}
	return (0);
}

