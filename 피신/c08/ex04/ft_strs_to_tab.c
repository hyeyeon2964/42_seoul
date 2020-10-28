/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 22:15:14 by hmyoung           #+#    #+#             */
/*   Updated: 2020/07/23 10:11:11 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int						get_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char					*ft_strcpy(char *str, int size)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char *)malloc(sizeof(char) * (size + 1));
	if (temp == 0)
		return (0);
	while (str[i])
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

t_stock_str				*set_stock_str(t_stock_str *tstock, char *str)
{
	tstock->str = str;
	tstock->size = get_len(str);
	tstock->copy = ft_strcpy(str, tstock->size);
	if (tstock->copy == 0)
		return (0);
	return (tstock);
}

void					free_stock(t_stock_str *tstock, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(tstock[i].copy);
		i++;
	}
	free(tstock);
}

struct s_stock_str		*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str *stock;
	t_stock_str *temp;
	int			i;

	stock = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (stock == 0)
		return (0);
	stock[ac].str = 0;
	i = 0;
	while (i < ac)
	{
		temp = set_stock_str(stock + i, av[i]);
		if (temp == 0)
		{
			free_stock(stock, i);
			return (0);
		}
		i++;
	}
	return (stock);
}
