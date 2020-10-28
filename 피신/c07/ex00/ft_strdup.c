/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 09:34:11 by hmyoung           #+#    #+#             */
/*   Updated: 2020/07/21 10:34:02 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*ft_malloc;
	int		i;

	i = 0;
	while (src[i])
		i++;
	ft_malloc = (char *)malloc(i * sizeof(char) + 1);
	if (!(ft_malloc))
		return (0);
	i = 0;
	while (src[i])
	{
		ft_malloc[i] = src[i];
		i++;
	}
	ft_malloc[i] = '\0';
	return (ft_malloc);
}
