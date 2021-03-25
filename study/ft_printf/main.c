# include <stdio.h>
#include "ft_printf.h"
int	main(void)
{
	// printf("%s", "hello");
	// printf("[%*.*s] \n",10, 3, "hello");
	// ft_printf("[%*.*s] \n",10, 3, "hello");
	// printf("---------------------\n");
	// printf("[%-*.*s] \n",10, 3, "hello");
	// ft_printf("[%-*.*s] \n",10, 3, "hello");
	// printf("---------------------\n");
	// printf("[%*.*s] \n",3, 10, "hello");
	// ft_printf("[%*.*s] \n",3, 10, "hello");
	// printf("---------------------\n");
	// printf("[%*.*d] \n", 10, 3, 1234);
	// ft_printf("[%*.*d] \n", 10, 3, 1234);
	// printf("---------------------\n");
	// printf("0flag :  [%05d]\n", 123);
	// ft_printf("0flag :  [%05d]\n", 123);
	// printf("---------------------\n");
	// printf("pre 5 :  [%.5d]\n",123);
	// ft_printf("pre 5 :  [%.5d]\n",123);
	// printf("---------------------\n");
	// printf("pre 1 :  [%.1d]\n", 123);
	// ft_printf("pre 1 :  [%.1d]\n", 123);
	// printf("---------------------\n");
	// printf("width 2: [%2d]\n", 123);
	// ft_printf("width 2: [%2d]\n", 123);
	// printf("---------------------\n");
	// printf("width 5: [%5d]\n", 123);
	// ft_printf("width 5: [%5d]\n", 123);
	// printf("---------------------\n");
	// printf("width 3 pre 5 [%3.5d]\n", 1234);
	// ft_printf("width 3 pre 5 [%3.5d]\n", 1234);
	// printf("---------------------\n");
	// printf("width 5 pre 6 [%5.6d]\n", 1234);
	// ft_printf("width 5 pre 6 [%5.6d]\n", 1234);
	// printf("---------------------\n");
	// printf("width 5 pre 6 [%5.6x]\n", 1234);
	// ft_printf("width 5 pre 6 [%5.6x]\n", 1234);
	// printf("---------------------\n");
	// printf("width 5 pre 6 [%x]\n", 1234);
	// ft_printf("width 5 pre 6 [%x]\n", 1234);
	// printf("---------------------\n");
	// printf("pre 5 :  [%.5x]\n",123);
	// ft_printf("pre 5 :  [%.5x]\n",123);
	// printf("---------------------\n");
	// printf("pre 1 :  [%.1x]\n", 123);
	// ft_printf("pre 1 :  [%.1x]\n", 123);
	// printf("---------------------\n");
	// printf("width 5 pre 6 [%5.6X]\n", 1234);
	// ft_printf("width 5 pre 6 [%5.6X]\n", 1234);
	// printf("---------------------\n");
	// printf("width 5 pre 6 [%-10X]\n", 1234);
	// ft_printf("width 5 pre 6 [%-10X]\n", 1234);
	// printf("---------------------\n");
	// printf("width 5 pre 6 [%-10X]\n", 1234);
	// ft_printf("width 5 pre 6 [%-10X]\n", 1234);
	//printf("---------------------\n");
	//printf("width 5 pre 6 [%p]\n", &"hello");
	//ft_printf("width 5 pre 6 [%p]\n   g_info.result: %d \n", &"hello", g_info.result);


	//ft_printf("%s ", "hello");
	// ft_printf("%*c \n", 5,'a');
	// printf("%*c \n", 5, 'a');
	// printf("result = %d \n ", g_info.result);
	// printf("--------------------- \n");
	// ft_printf("%c \n", 'a');
	// printf("%c \n", 'a');
	// printf("zero: %d  minus : %d  width: %d  width_star: %d  type: %c dot: %d precision: %d \n", g_info.zero, g_info.minus, g_info.width, g_info.width_star, g_info.type, g_info.dot, g_info.precision);
	printf("    result = %d     g_info.result = %d \n", ft_printf("%c", 'c'), g_info.result);
	return (0);
}
