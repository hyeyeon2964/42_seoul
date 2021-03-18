/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:27:56 by hmyoung           #+#    #+#             */
/*   Updated: 2021/03/11 20:43:49 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_str(char *str)
{
	write(1, str, ft_strlen(str));
	g_info.result += ft_strlen(str) - 1;
}

char *make_flag(size_t width, char c)
{
	char *str;
	int index;

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

void print_etc(void)
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
	else if(g_info.precision_star == 1)
		g_info.precision = va_arg(ap, int);

	if (g_info.type == '%')
		print_etc();
}

