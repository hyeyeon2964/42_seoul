/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:34:19 by hmyoung           #+#    #+#             */
/*   Updated: 2021/03/11 20:44:24 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	int i;
	int result;
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
			print_result(ap);
		}
		i++;
	}
	va_end(ap);
	return (g_info.result);
}

int main()
{	
	//ft_printf("hello");
		ft_printf("%010% \n");
		printf("%010% \n");
	printf("zero: %d  minus : %d  width: %d  width_star: %d  type: %c dot: %d precision: %d \n", g_info.zero, g_info.minus, g_info.width, g_info.width_star, g_info.type, g_info.dot, g_info.precision);
	printf("%d", g_info.result);
	//ft_printf("%*.5s \n", 10);
	//printf("zero: %d  minus : %d  width: %d   width_star: %d precision_star: %d type: %c precision: %d \n", g_info.zero, g_info.minus, g_info.width, g_info.width_star, g_info.precision_star, g_info.type, g_info.precision);

	return (0);
}
