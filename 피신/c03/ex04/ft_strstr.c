/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 13:01:42 by hmyoung           #+#    #+#             */
/*   Updated: 2020/07/15 10:22:16 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strstr(char *str, char *to_find)
{
	int	i;
	int j;

	i = 0;
	if (*to_find == '\0')
		return (&str[0]);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while (1)
			{
				if (to_find[j] == '\0')
					return (&str[i]);
				if (!(str[i + j] == to_find[j]))
					break ;
				j++;
			}
		}
		i++;
	}
	return (0);
}
