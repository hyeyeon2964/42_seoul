/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 21:13:38 by hmyoung           #+#    #+#             */
/*   Updated: 2020/07/19 19:51:31 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		find_prime(int nb)
{
	long long i;

	i = 2;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	int i;

	i = 2;
	if (nb <= 1)
		return (2);
	while (1)
	{
		if (find_prime(nb))
			return (nb);
		nb += 1;
	}
}
