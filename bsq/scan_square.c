/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <hmyoung@student42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 21:54:24 by hmyoung           #+#    #+#             */
/*   Updated: 2020/07/22 21:54:26 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		compare(int a, int b, int c)
{
	a = a > b ? b : a;
	return ((a > c ? c : a) + 1);
}

void	set_max(map_info *info, int i, int j)
{
	if (info->map[i][j] > info->max)
	{
		info->max = info->map[i][j];
		info->max_x = j;
		info->max_y = i;
	}
}

void	scan_square(map_info *info)
{
	int i;
	int j;

	i = 1;
	info->max = -1;
	while (i < info->y)
	{
		j = 1;
		while (j < info->x)
		{
			if (info->map[i][j] > 0)
			{
				info->map[i][j] = compare(info->map[i - 1][j - 1],
						info->map[i - 1][j], info->map[i][j - 1]);
				set_max(info, i, j);
			}
			j++;
		}
		i++;
	}
}
