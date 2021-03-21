/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <hmyoung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:17:55 by hmyoung           #+#    #+#             */
/*   Updated: 2021/03/21 21:12:04 by hmyoung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	struct_reset(void)
{
	g_info.zero = 0;
	g_info.minus = 0;
	g_info.width = 0;
	g_info.dot = 0;
	g_info.width_star = 0;
	g_info.precision_star = 0;
	g_info.precision = -1;
	g_info.len = 0;
	g_info.type = '0';
}

int		finish_check(const char *format, int i)
{
	if (format[i] == 'c' || format[i] == 's' || format[i] == 'p' ||
			format[i] == 'd' || format[i] == 'i' || format[i] == 'u' ||
			format[i] == 'x' || format[i] == 'X' || format[i] == '%')
	{
		g_info.type = format[i];
		return (0);
	}
	else
		return (1);
}

int		integer_len(int num)
{
	int len;

	len = 0;
	while (num > 0)
	{
		len++;
		num /= 10;
	}
	g_info.len = len;
	return (len);
}

void	precision_check(const char* format, int i)
{
	if (format[i-1] == '.')
		g_info.precision_star = 1;
	else
		g_info.width_star = 1;
}
int		option_check(const char *format, int i)
{
	while (finish_check(format, i) != 0)
	{
		if (format[i] == '-')
			g_info.minus = 1;
		else if (format[i] == '0')
			g_info.zero = 1;
		else if (format[i] >= '1' && format[i] <= '9')
		{
			g_info.width = atoi(&format[i]);
			i = i + integer_len(g_info.width) - 1;
		}
		else if (format[i] == '*')
			precision_check(format, i);
		else if (format[i] == '.')
		{
			g_info.dot = 1;
			g_info.precision = atoi(&format[i + 1]);
			i = i + integer_len(g_info.precision);
		}
		i++;
	}
	return (i);
}
