/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <hmyoung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:53:27 by hmyoung           #+#    #+#             */
/*   Updated: 2021/03/25 20:48:17 by hmyoung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_before_s(char* str, char *blank)
{
	if (g_info.minus == 1)
		str = ft_strjoin(str, blank);
	else
		str = ft_strjoin(blank, str);
	return (str);
}

void	print_s(va_list ap)
{
	char	*str;
	char	*blank;
	int		strlen;

	blank = "";
	if ((str = ft_strdup(va_arg(ap, char*))) == NULL)
		str = ft_strdup("(null)");
	if ((g_info.precision_star == 1 && g_info.precision == -1)
	|| g_info.precision == 0)
		return ;
	strlen = ft_strlen(str);
	if (g_info.precision < strlen)
	{
		str[g_info.precision] = '\0';
		str = ft_strdup(str);
		strlen = ft_strlen(str);
	}
	if (g_info.width == 0)
		g_info.width = strlen;
	if (g_info.width > strlen)
	{
		if (g_info.zero == 1)
			blank = make_flag(g_info.width - strlen, '0');
		else
			blank = make_flag(g_info.width - strlen, ' ');
	}
	str = print_before_s(str, blank);
	print_str(str);
	return ;
}

void	print_c(va_list ap)
{
	char *str;
	char c;

	c = va_arg(ap,  int);
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
