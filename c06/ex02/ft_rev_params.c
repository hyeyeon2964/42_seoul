/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:14:56 by hmyoung           #+#    #+#             */
/*   Updated: 2020/07/20 14:13:35 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str++, 1);
	}
}

int		main(int ac, char **av)
{
	int i;

	i = ac - 1;
	if (ac > 1)
	{
		while (i > 0)
		{
			ft_putstr(av[i]);
			write(1, "\n", 1);
			i--;
		}
	}
}
