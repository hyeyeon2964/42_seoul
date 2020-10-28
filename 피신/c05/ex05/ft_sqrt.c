/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 20:06:50 by hmyoung           #+#    #+#             */
/*   Updated: 2020/07/19 19:33:34 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	long long square;

	square = 1;
	if (nb <= 0)
		return (0);
	else if (nb == 1)
		return (1);
	while (nb >= square * square)
	{
		if (square * square == nb)
			return ((int)square);
		else if (square * square < 0)
			return (0);
		else
			square++;
	}
	return (0);
}
