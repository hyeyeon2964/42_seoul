/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <hmyoung@student42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 21:52:29 by hmyoung           #+#    #+#             */
/*   Updated: 2020/07/22 21:52:39 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int av, char **ac)
{
	int			i;
	int			j;
	map_info	info;

	i = 1;
	if (av > 1)
	{
		while (i < av)
		{
			info = file_to_struct(ac[i]);
			scan_square(&info);
			print_res(&info);
			i++;
		}
	}
	return (0);
}
