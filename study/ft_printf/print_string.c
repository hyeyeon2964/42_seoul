/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:57:43 by hmyoung           #+#    #+#             */
/*   Updated: 2021/03/30 20:57:47 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_before_s(char *str, char *blank)
{
	if (g_info.minus == 1)
		str = ft_strjoin(str, blank);
	else
		str = ft_strjoin(blank, str);
	return (str);
}

char	*split_str(char *str)
{
	char	*result;

	result = str;
	result[g_info.precision] = '\0';
	result = ft_strdup(str);
	g_info.len = ft_strlen(str);
	return (str);
}

void	print_s(va_list ap)
{
	char	*str;
	char	*blank;

	blank = "";
	if ((str = ft_strdup(va_arg(ap, char*))) == NULL)
		str = ft_strdup("(null)");
	if (str[0] == '\0' || (g_info.precision_star == 1 && g_info.precision == -1)
	|| g_info.precision == 0)
		if (str[0] == '\0')
		{
			print_str(make_flag(g_info.width, ' '));
			return ;
		}
	g_info.len = ft_strlen(str);
	if (g_info.precision < g_info.len)
		str = split_str(str);
	if (g_info.width == 0)
		g_info.width = g_info.len;
	if (g_info.width > g_info.len && g_info.zero == 1)
		blank = make_flag(g_info.width - g_info.len, '0');
	else if (g_info.width > g_info.len)
		blank = make_flag(g_info.width - g_info.len, ' ');
	str = print_before_s(str, blank);
	print_str(str);
}

void	print_c(va_list ap)
{
	char	*str;
	char	c;

	c = va_arg(ap, int);
	if (g_info.width == 0)
		g_info.width = 1;
	str = make_flag(g_info.width, ' ');
	if (g_info.minus == 1)
		str[0] = c;
	else
		str[ft_strlen(str) - 1] = c;
	write(1, str, g_info.width);
	g_info.result += g_info.width;
}
