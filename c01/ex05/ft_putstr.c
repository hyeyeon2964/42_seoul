/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:55:18 by hmyoung           #+#    #+#             */
/*   Updated: 2020/07/12 11:28:28 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	char	a;
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		a = str[i];
		write(1, &a, 1);
		i++;
	}
}
