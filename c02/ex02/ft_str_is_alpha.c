/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:21:15 by hmyoung           #+#    #+#             */
/*   Updated: 2020/07/09 21:45:23 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int		ft_str_is_alpha(char *str)
{
	int		i;
	char	a;

	i = 0;

	if (*str == '\0')
		return (1);
	while(*(str + i) != '\0')
	{
		a = *(str + i);
		if(('A' <= a) && ('z' >= a))
				return (1);
		else
			i++;
}
return (0);
}
int		main(void)
{
	char a;
	
	a = ft_str_is_alpha("ac1122233") + '0';
	write(1, &a, 1);
	a = ft_str_is_alpha(" ") + '0';
	write(1, &a, 1);
}
