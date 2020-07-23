/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 09:43:06 by hmyoung           #+#    #+#             */
/*   Updated: 2020/07/21 12:45:03 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	long long	i;
	long long	len;
	int			*ft_malloc;

	len = max - min;
	i = 0;
	if (min >= max)
		return (0);
	if (!(ft_malloc = (int *)malloc(sizeof(int) * len)))
		return (0);
	while (min < max)
	{
		ft_malloc[i] = min;
		i++;
		min++;
	}
	return (ft_malloc);
}
