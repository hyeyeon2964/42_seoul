/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 16:36:15 by hmyoung           #+#    #+#             */
/*   Updated: 2020/07/12 11:39:55 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tap(int *tab, int size)
{
	int temp;
	int index;
	int length;

	index = 0;
	length = size - 1;
	while (index < length)
	{
		temp = tab[index];
		tab[index] = tab[length];
		tab[length] = temp;
		index++;
		length--;
	}
}
