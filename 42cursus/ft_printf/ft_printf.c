/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:34:19 by hmyoung           #+#    #+#             */
/*   Updated: 2021/03/09 20:49:43 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int ft_printf(const char *format, ...)
{
	int i;
	int result;

	result 	= 0;
	i 		= 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
		}
		else
		{
			i = option_check(format, i + 1);
		}
		i++;
	}
	printf("zero: %d  minus : %d  width: %d   star: %d  type: %c \n", g_info.zero, g_info.minus, g_info.width, g_info.star, g_info.type);
	return (result);
}

int main()
{
	printf("1234 \n ");
	ft_printf("%10d \n");
	ft_printf("%*.5s \n");
	printf("-------option----------\n");
	return (0);
}
