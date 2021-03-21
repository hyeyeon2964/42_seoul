/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <hmyoung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:34:19 by hmyoung           #+#    #+#             */
/*   Updated: 2021/03/21 21:11:36 by hmyoung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
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

int	main(void)
{
	//printf("%s", "hello");
	printf("[%*.*s] \n",10, 3, "hello");
	ft_printf("[%*.*s] \n",10, 3, "hello");
	printf("---------------------\n");
	printf("[%-*.*s] \n",10, 3, "hello");
	ft_printf("[%-*.*s] \n",10, 3, "hello");
	printf("---------------------\n");
	printf("[%*.*s] \n",3, 10, "hello");
	ft_printf("[%*.*s] \n",3, 10, "hello");
	printf("---------------------\n");
	//ft_printf("%s ", "hello");
	// ft_printf("%*c \n", 5,'a');
	// printf("%*c \n", 5, 'a');
	// printf("result = %d \n ", g_info.result);
	// printf("--------------------- \n");
	// ft_printf("%c \n", 'a');
	// printf("%c \n", 'a');
	// printf("zero: %d  minus : %d  width: %d  width_star: %d  type: %c dot: %d precision: %d \n", g_info.zero, g_info.minus, g_info.width, g_info.width_star, g_info.type, g_info.dot, g_info.precision);
	// printf("result = %d", g_info.result);
	return (0);
}
