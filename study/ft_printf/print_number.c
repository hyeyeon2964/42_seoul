/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:59:21 by hmyoung           #+#    #+#             */
/*   Updated: 2021/03/30 20:59:24 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*before_print_d(void)
{
	char *blank;

	blank = "";
	if (g_info.precision > -1)
		g_info.zero = 0;
	if (g_info.width == 0 && g_info.precision == -1)
		return (blank);
	if ((g_info.width > g_info.len) && g_info.zero == 1)
		blank = make_flag(g_info.width - g_info.len, '0');
	if ((g_info.width > g_info.len) && g_info.zero == 0)
		blank = make_flag(g_info.width - g_info.len, ' ');
	return (blank);
}

char	*make_str(long long num)
{
	char		*str;
	char		*blank;
	long long	n;

	blank = "";
	n = num;
	str = ft_itoa(n);
	g_info.len = ft_strlen(str);
	if (n == 0 && (g_info.dot == 1 && g_info.precision == 0))
		return (make_flag(g_info.width, ' '));
	if (num < 0)
	{
		n *= -1;
		str = ft_itoa(n);
		g_info.len -= 1;
	}
	if (g_info.precision > g_info.len)
	{
		blank = make_flag(g_info.precision - g_info.len, '0');
		str = ft_strjoin(blank, str);
	}
	if (num < 0)
		str = ft_strjoin("-", str);
	g_info.len = ft_strlen(str);
	return (str);
}

char	*check_sort(char *str, char *blank)
{
	char *result;

	if (g_info.minus == 1 && g_info.zero == 0)
		result = (ft_strjoin(str, blank));
	else
		result = (ft_strjoin(blank, str));
	return (result);
}

char	*set_minus(char *str, long long num)
{
	str[0] = '-';
	str[ft_strlen(str) - integer_len(num) - 1] = '0';
	return (str);
}

void	print_d(va_list ap)
{
	long long	num;
	char		*str;
	char		*blank;

	if (g_info.type == 'd' || g_info.type == 'i')
		num = va_arg(ap, int);
	if (g_info.type == 'u')
		num = va_arg(ap, unsigned int);
	str = make_str(num);
	blank = before_print_d();
	if ((g_info.precision <= g_info.len) && (g_info.width <= g_info.len))
	{
		print_str(str);
		return ;
	}
	if (g_info.dot == 1 && g_info.precision == 0 && num == 0)
	{
		print_str(make_flag(g_info.width, ' '));
		return ;
	}
	str = check_sort(str, blank);
	if (g_info.width > g_info.len && g_info.zero == 1 && num < 0)
		str = set_minus(str, num);
	print_str(str);
}
