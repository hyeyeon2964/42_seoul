/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:56:38 by hmyoung           #+#    #+#             */
/*   Updated: 2020/07/13 15:07:50 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_str_is_numeric(char *str)
{
	char	a;

	while (*(str) != '\0')
	{
		a = *(str++);
		if (!((a >= '0' && a <= '9')))
		{
			return (0);
		}
	}
	return (1);
}