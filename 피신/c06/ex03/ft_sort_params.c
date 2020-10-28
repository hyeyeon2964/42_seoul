/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:24:22 by hmyoung           #+#    #+#             */
/*   Updated: 2020/07/21 08:47:44 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void			ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str++, 1);
	}
}

int				ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

void			sort(int ac, char *str[])
{
	int			i;
	int			j;
	char		*temp;

	i = 1;
	while (i < ac)
	{
		j = 2;
		while (j < ac)
		{
			if (ft_strcmp(str[j - 1], str[j]) > 0)
			{
				temp = str[j - 1];
				str[j - 1] = str[j];
				str[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int				main(int ac, char **av)
{
	int i;

	if (ac >= 2)
	{
		sort(ac, av);
		i = 1;
		while (i < ac)
		{
			ft_putstr(av[i]);
			write(1, "\n", 1);
			i++;
		}
	}
}
