/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 15:29:52 by hmyoung           #+#    #+#             */
/*   Updated: 2020/07/16 16:57:08 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		valid_base(char *base)
{
	int i;
	int j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+' || (9 <= str[i] && 
					str[i] <= 13) || str[i] == ' ')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		check_sign(char *str, i)
{
	if (str[i] == '-')
		return (-1);
	else if (str[i] == '+' || (9 <=str[i] && str[i] >= 13)
			|| str[i] == ' ')
		return (1);
	else
		return (0);
}

int		find_len(char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int sign;
	int result;
	int len;

	i = 0;
	sign = 1;
	result = 0;
	len = find_len(base);
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = find_result(str, i);
			break;
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
}
