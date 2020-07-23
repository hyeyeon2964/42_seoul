/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 12:45:47 by hmyoung           #+#    #+#             */
/*   Updated: 2020/07/21 16:43:09 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		find_len(char *str)
{
	int len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

char	*empty_size(void)
{
	char *result;

	result = (char *)malloc(sizeof(char) * 1);
	result[0] = 0;
	return (result);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int dest_i;

	i = 0;
	dest_i = find_len(dest);
	while (src[i])
	{
		dest[dest_i] = src[i];
		dest_i++;
		i++;
	}
	dest[dest_i] = '\0';
	return (dest);
}

char	*ft_join(char *arr, int size, char **strs, char *sep)
{
	int i;
	int dest_i;

	i = 1;
	arr = ft_strcat(arr, strs[0]);
	while (i < size)
	{
		ft_strcat(arr, sep);
		ft_strcat(arr, strs[i]);
		i++;
	}
	dest_i = find_len(arr);
	arr[dest_i] = '\0';
	return (arr);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char		*arr;
	int			len;
	int			i;

	i = 0;
	len = 0;
	if (size == 0)
	{
		arr = empty_size();
		return (arr);
	}
	while (i < size)
	{
		len += find_len(strs[i]);
		i++;
	}
	len += (size - 1) * find_len(sep) + 1;
	arr = (char*)malloc(sizeof(char) * len);
	arr[0] = 0;
	ft_join(arr, size, strs, sep);
	return (arr);
}
