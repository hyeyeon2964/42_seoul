/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:40:03 by hmyoung           #+#    #+#             */
/*   Updated: 2021/03/30 20:40:07 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*make_str_p(char *str)
{
	char	*blank;
	char	*zero;

	zero = "";
	blank = "";
	g_info.len = ft_strlen(str);
	if (g_info.precision > g_info.len)
	{
		zero = make_flag(g_info.precision - g_info.len, '0');
		str = ft_strjoin(zero, str);
	}
	str = ft_strjoin("0x", str);
	g_info.len = ft_strlen(str);
	if (g_info.width > g_info.len)
		blank = make_flag(g_info.width - g_info.len, ' ');
	if (g_info.minus == 1)
		str = ft_strjoin(str, blank);
	else
		str = ft_strjoin(blank, str);
	return (str);
}

void	print_p(va_list ap)
{
	long long	p;
	char		*str;

	p = va_arg(ap, long long);
	if (p == 0 && g_info.dot == 1)
		str = "";
	else
		str = ft_itoh(p);
	str = make_str_p(str);
	if (g_info.width == 0 && g_info.precision == -1)
	{
		print_str(str);
		return ;
	}
	print_str(str);
}
