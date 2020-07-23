/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 10:13:14 by hmyoung           #+#    #+#             */
/*   Updated: 2020/07/21 14:15:20 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_ultimate_range(int **range, int min, int max)
{
	int			*temp;
	long long	len;
	long long	i;

	i = 0;
	len = max - min;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	temp = (int*)malloc(sizeof(int) * len);
	if (temp == 0)
		return (-1);
	while (min < max)
	{
		temp[i] = min;
		min++;
		i++;
	}
	*range = temp;
	return ((int)len);
}
