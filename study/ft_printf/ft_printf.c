/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <hmyoung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:34:19 by hmyoung           #+#    #+#             */
/*   Updated: 2021/03/25 17:10:50 by hmyoung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int i;
	va_list ap;
	va_start(ap, format);
	g_info.result = 0;

	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			g_info.result++;
		}
		else
		{
			struct_reset();
			i = option_check(format, i + 1);
			save_option(ap);
		}
		i++;
	}
	va_end(ap);
	return (g_info.result);
}
