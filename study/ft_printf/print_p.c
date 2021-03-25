/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <hmyoung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:55:04 by hmyoung           #+#    #+#             */
/*   Updated: 2021/03/25 16:55:01 by hmyoung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *before_print_p(char *str)
{
	int len;
	char *blank;

	blank = "";
	len = ft_strlen(str);
	if (g_info.width == 0 && g_info.precision == -1)
		return blank;
	if (len > g_info.width)
		g_info.width = 0;
	if (len > g_info.precision)
		g_info.precision = -1;
	if (g_info.precision > g_info.width)
		blank = make_flag(g_info.precision - len, '0');
	else if ((g_info.width > g_info.precision)
			&& g_info.zero == 1)
		 blank = make_flag(g_info.width - len, '0');
	else if (g_info.width > g_info.precision)
		blank = make_flag(g_info.width - len , ' ');
	return (blank);
}

void print_p(va_list ap)
{
	long long p;
	char *str;
	char *blank;

	p = va_arg(ap, long long);
	str = ft_strjoin("0x", ft_itoh(p));
	if (ft_strlen(str) == 0)
	{
		if (g_info.dot == 1)
			print_str("0x");
		else
			print_str("0x0");
		return ;
	}
	if (g_info.width == 0 && g_info.precision == -1)
	{
		print_str(str);
		return ;
	}
	else
	{
		blank = before_print_p(str);
		if (g_info.minus == 1)
			str = ft_strjoin(str, blank);
		else
			str = ft_strjoin(blank, str);
	}
	print_str(str);
}
