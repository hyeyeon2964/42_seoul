/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <hmyoung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:56:43 by hmyoung           #+#    #+#             */
/*   Updated: 2021/03/25 16:17:53 by hmyoung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *before_print_x(char *str)
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

void print_x(va_list ap)
{
	int num;
	char *str;
	char *blank;

	num = va_arg(ap, unsigned int);

	str = ft_itoh(num);
	blank = before_print_x(str);
	if (g_info.precision == 0)
		return ;
	if (g_info.precision == -1 && g_info.width == 0)
	{
		print_str(str);
		return ;
	}
	if (g_info.minus == 1)
		str = ft_strjoin(str, blank);
	else
		str = ft_strjoin(blank, str);
	print_str(str);
}
