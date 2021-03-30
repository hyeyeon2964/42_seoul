/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:33:50 by hmyoung           #+#    #+#             */
/*   Updated: 2021/03/30 20:33:52 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		struct_reset(void)
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

int			finish_check(const char *format, int i)
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

long long	integer_len(long long num)
{
	long long len;

	len = 0;
	if (num < 0)
		num *= -1;
	while (num > 0)
	{
		len++;
		num /= 10;
	}
	g_info.len = len;
	return (len);
}

void		precision_check(const char *format, int i)
{
	if (format[i - 1] == '.')
		g_info.precision_star = 1;
	else
		g_info.width_star = 1;
}

int			option_check(const char *format, int i)
{
	while (finish_check(format, i) != 0)
	{
		if (format[i] == '-')
			g_info.minus = 1;
		else if (format[i] == '0')
			g_info.zero = 1;
		else if (format[i] >= '1' && format[i] <= '9')
		{
			g_info.width = ft_atoi(&format[i]);
			i = i + integer_len(g_info.width) - 1;
		}
		else if (format[i] == '*')
			precision_check(format, i);
		else if (format[i] == '.')
		{
			g_info.dot = 1;
			g_info.precision = ft_atoi(&format[i + 1]);
			if (format[i + 1] == '0')
				i++;
			i = i + integer_len(g_info.precision);
		}
		i++;
	}
	return (i);
}
