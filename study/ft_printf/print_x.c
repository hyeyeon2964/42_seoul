/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:58:59 by hmyoung           #+#    #+#             */
/*   Updated: 2021/03/30 20:59:01 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*before_print_x(void)
{
	char	*blank;

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

char	*make_str_x(long long num)
{
	char		*str;
	char		*blank;
	long long	n;

	blank = "";
	n = num;
	str = ft_itoh(n);
	g_info.len = ft_strlen(str);
	if (n == 0 && (g_info.dot == 1 && g_info.precision == 0))
		return (make_flag(g_info.width, ' '));
	if (num < 0)
	{
		n *= -1;
		str = ft_itoh(n);
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

void	print_x(va_list ap)
{
	long long	num;
	char		*str;
	char		*blank;

	num = va_arg(ap, unsigned int);
	str = make_str_x(num);
	blank = before_print_x();
	if ((g_info.precision == -1 && g_info.width == 0)
		|| ((g_info.precision <= g_info.len) && (g_info.width <= g_info.len)))
	{
		print_str(str);
		return ;
	}
	if (g_info.dot == 1 && g_info.precision == 0 && num == 0)
	{
		print_str(make_flag(g_info.width, ' '));
		return ;
	}
	if (g_info.minus == 1 && g_info.zero == 0)
		str = ft_strjoin(str, blank);
	else
		str = ft_strjoin(blank, str);
	if (g_info.width > g_info.len && g_info.zero == 1 && num < 0)
		str = set_minus(str, num);
	print_str(str);
}
