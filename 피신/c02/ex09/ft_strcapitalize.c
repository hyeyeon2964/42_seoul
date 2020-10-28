/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <hmyoung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 15:10:12 by hmyoung           #+#    #+#             */
/*   Updated: 2020/07/14 11:10:26 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	upcase(char *str, int i)
{
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] = str[i] - 32;
}

void	lowcase(char *str, int i)
{
	if (str[i] >= 'A' && str[i] <= 'Z')
		str[i] = str[i] + 32;
}

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0)
			upcase(str, 0);
		else
			lowcase(str, i);
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i - 1] >= 'a' && str[i - 1] <= 'z') &&
				!(str[i - 1] >= 'A' && str[i - 1] <= 'Z'))
		{
			if (!(str[i - 1] >= '0' && str[i - 1] <= '9'))
				upcase(str, i);
		}
		i++;
	}
	return (str);
}
