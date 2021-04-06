/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 14:41:09 by hmyoung           #+#    #+#             */
/*   Updated: 2020/07/19 16:14:18 by hmyoung          ###   ########.fr       */
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

	i = 1;
	while (ac > i)
	{
		ft_putstr(av[i]);
		write(1, "\n", 1);
		i++;
	}
}
