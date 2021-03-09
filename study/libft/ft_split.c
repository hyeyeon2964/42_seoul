/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:09:40 by hmyoung           #+#    #+#             */
/*   Updated: 2020/11/10 18:36:56 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*make_str_part(char const *str, int len)
{
	char	*part;
	int		i;

	if (!(part = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		part[i] = str[i];
		i++;
	}
	part[i] = '\0';
	return (part);
}

size_t		word_count(char const *s, char c)
{
	size_t i;
	size_t cnt;

	i = 0;
	cnt = 0;
	if (s[i] == '\0')
		return (0);
	if (s[i] && s[i] != c)
	{
		i++;
		cnt++;
	}
	while (s[i])
	{
		if (s[i] == c)
		{
			if (s[i + 1] && s[i + 1] != c)
				cnt++;
		}
		i++;
	}
	return (cnt);
}

char		**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	res_len;
	size_t	res_index;
	size_t	start;

	res_len = word_count(s, c);
	if (!(result = (char **)malloc(sizeof(char *) * (res_len + 1))))
		return (0);
	i = 0;
	start = 0;
	res_index = 0;
	while (s[i] && res_index < res_len)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		result[res_index] = make_str_part(s + start, i - start);
		res_index++;
	}
	result[res_index] = NULL;
	return (result);
}
