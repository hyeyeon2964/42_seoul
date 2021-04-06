/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:31:20 by hmyoung           #+#    #+#             */
/*   Updated: 2020/07/19 14:51:49 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_nb(char *a)
{
	if (*a == '\0')
		return ;
	else
	{
		print_nb(a + 1);
		write(1, a, 1);
	}
}

void	ft_putnbr(int nb)
{
	char	a[11];
	int		i;

	i = 0;
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb == 0)
		write(1, "0", 1);
	else if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	while (nb > 0)
	{
		a[i] = (nb % 10) + '0';
		nb = nb / 10;
		i++;
	}
	a[i] = '\0';
	print_nb(a);
}
