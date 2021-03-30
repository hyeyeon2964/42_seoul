/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:22:26 by hmyoung           #+#    #+#             */
/*   Updated: 2021/03/30 20:22:29 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isspace(char str)
{
	if ((9 <= str && str <= 13) || str == 32)
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	int		sign;
	int		i;
	long	result;

	i = 0;
	while (ft_isspace(str[i]) == 1)
	{
		i++;
	}
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		if (result > 2147483647 && sign == 1)
			return (-1);
		if (result > 2147483648 && sign == -1)
			return (0);
		i++;
	}
	return (sign * result);
}

char	*ft_itoa(long long n)
{
	char	*result;
	size_t	len;
	size_t	i;

	len = get_len(n);
	if (!(result = (char *)malloc(len + 1)))
		return (NULL);
	result[len] = '\0';
	if (n < 0)
	{
		result[0] = '-';
		i = 1;
	}
	else
		i = 0;
	while (i < len)
	{
		len--;
		result[len] = '0' + n % 10 * (n < 0 ? -1 : 1);
		n /= 10;
	}
	return (result);
}

char	*ft_straddchr(char *str, char c, int pos)
{
	char	*res;
	int		i;

	i = -1;
	if (ft_strlen(str) + 1 < 2)
	{
		res = malloc(2);
		res[0] = c;
		res[1] = '\0';
		return (res);
	}
	res = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (pos == 0)
		res[ft_strlen(str)] = c;
	else
		*(res) = c;
	while (*(str + (++i)))
		if (pos == 0)
			*(res + i) = *(str + i);
		else
			*(res + i + 1) = str[i];
	res[ft_strlen(str) + 1] = '\0';
	free(str);
	return (res);
}

char	*ft_itoh(long long n)
{
	char		*res;
	char		*alpha;
	char		*num;
	long long	r;

	if (n == 0)
		return ("0");
	if (g_info.type == 'X')
		alpha = ft_strdup("ABCDEF");
	else
		alpha = ft_strdup("abcdef");
	num = ft_strdup("0123456789");
	res = ft_strdup("");
	while (n > 0)
	{
		r = n % 16;
		n = n >> 4;
		if (r >= 10)
			res = ft_straddchr(res, alpha[r - 10], 1);
		else
			res = ft_straddchr(res, num[r], 1);
	}
	free(num);
	free(alpha);
	return (res);
}
