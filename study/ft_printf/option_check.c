/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:17:55 by hmyoung           #+#    #+#             */
/*   Updated: 2021/03/09 20:18:05 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
void	struct_reset()
{
	g_info.zero			= 0;
	g_info.minus		= 0;
	g_info.width		= 0;
	g_info.dot			= 0;
	g_info.star			= 0;
	g_info.precision	= 0;
	char	type		= '0';
}

int		option_check(const char *format, int i)
{
	int finish;

	finish = 0;
	while (finish != 1)
	{
		finish = finish_check(format, i);
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
			g_info.star = 1;
		else if (format[i] == '.')
		{
			g_info.dot = 1;
			g_info.precision = atoi(&format[i]);
			i = i + integer_len(g_info.precision) - 1;
		}
		i++;
	}
	return (i + 1);
}

int		finish_check(const char *format, int i)
{
	if (format[i] == 'c' || format[i] == 's' || format[i] == 'p' ||
			format[i] == 'd' || format[i] == 'i' || format[i] == 'u' ||
			format[i] == 'x' || format[i] == 'X' || format[i] == '%')
	{
		g_info.type = format[i];
		return (1);
	}
	else
		return (0);
}

int		integer_len(int num)
{
	int len;

	len = 0;
	while (num >= 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}
