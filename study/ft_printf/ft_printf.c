/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:19:07 by hmyoung           #+#    #+#             */
/*   Updated: 2021/03/30 20:19:10 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;

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
