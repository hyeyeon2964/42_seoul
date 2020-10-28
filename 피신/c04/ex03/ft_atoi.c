/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 09:34:03 by hmyoung           #+#    #+#             */
/*   Updated: 2020/07/19 15:08:54 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		find_result(char *str, int i)
{
	int result;

	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result);
}

int		check_sign(char *str, int i)
{
	if (str[i] == '-')
		return (-1);
	else if (str[i] == '+' || (9 <= str[i] && str[i] <= 13)
			|| str[i] == ' ')
		return (1);
	else
		return (0);
}

int		ft_atoi(char *str)
{
	int sign;
	int result;
	int	i;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = find_result(str, i);
			break ;
		}
		else
		{
			sign *= check_sign(str, i);
			if (sign == 1 || sign == -1)
				i++;
			else if (sign == 0)
				return (0);
		}
	}
	result *= sign;
	return (result);
}
