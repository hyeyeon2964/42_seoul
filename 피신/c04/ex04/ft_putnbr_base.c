/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 11:59:51 by hmyoung           #+#    #+#             */
/*   Updated: 2020/07/19 15:29:49 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		find_len(char *arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int		valid_base(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	print_arr(char *arr)
{
	if (*arr == '\0')
		return ;
	else
	{
		print_arr(arr + 1);
		write(1, arr, 1);
	}
}

void	create_arr(char *base, int nbr, int len)
{
	char	arr[11];
	int		i;

	i = 0;
	if (nbr == -2147483648)
	{
		arr[i] = base[-(nbr % len)];
		nbr = -(nbr / len);
		i++;
		write(1, "-", 1);
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	while (nbr != 0)
	{
		arr[i] = base[nbr % len];
		nbr /= len;
		i++;
	}
	arr[i] = '\0';
	print_arr(arr);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int len;

	if (valid_base(base) == 0)
		return ;
	if (nbr == 0)
		write(1, "0", 1);
	len = find_len(base);
	create_arr(base, nbr, len);
}
