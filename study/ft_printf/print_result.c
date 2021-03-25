/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <hmyoung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:27:56 by hmyoung           #+#    #+#             */
/*   Updated: 2021/03/25 20:41:30 by hmyoung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
void print_str(char *str)
{
	write(1, str, ft_strlen(str));
	g_info.result += ft_strlen(str);
}

char *make_flag(int width, char c)
{
	char	*str;
	int		index;

	index = 0;
	if (!(str = (char *)malloc(width + 1)))
		return (0);
	while (index != width)
	{
		str[index++] = c;
	}
	str[index] = '\0';
	return (str);
}

void print_per(void)
{
	char *str;

	if (g_info.zero == 1)
		str = make_flag(g_info.width, '0');
	else
		str = make_flag(g_info.width, ' ');
	if (g_info.minus == 1)
		str[0] = '%';
	else
		str[ft_strlen(str) - 1] = '%';
	print_str(str);
}

void print_result(va_list ap)
{
	if (g_info.type == '%')
		print_per();
	else if (g_info.type == 'c')
		print_c(ap);
	else if (g_info.type == 's')
		print_s(ap);
	else if
		(g_info.type == 'd' || g_info.type == 'i'
		|| g_info.type == 'u')
			print_d(ap);
	else if (g_info.type == 'x' || g_info.type == 'X')
		print_x(ap);
	else if (g_info.type == 'p')
		print_p(ap);
}

void save_option(va_list ap)
{
	if (g_info.width_star == 1)
	{
		if ((g_info.width = va_arg(ap, int)) < 0)
		{
			g_info.minus = 1;
			g_info.width = g_info.width * -1;
		}
		else if (g_info.width == 0)
			g_info.zero = 1;
	}
	if(g_info.precision_star == 1)
		g_info.precision = va_arg(ap, int);
	print_result(ap);
}
