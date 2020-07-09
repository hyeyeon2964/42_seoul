/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 22:16:49 by hmyoung           #+#    #+#             */
/*   Updated: 2020/07/09 22:20:44 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_str_is_uppercase(char *str)
{
	char a;

	if (*str == '\0')
		return (1);
	while (*str != '\0')
	{
		a = *(str++);
		if (a < 'A' || a > 'Z')
			return (0);
	}
	return (1);
}

int     ft_str_is_lowercase(char *str);

int     main(void)
{
	int result;

	result = ft_str_is_uppercase("abcde");
	printf("%d", result);
	result = ft_str_is_uppercase("ADDF");
	printf("%d",result);
	result = ft_str_is_uppercase("1234ABC");
	printf("%d",result);
	result = ft_str_is_uppercase("?1?!!");
	printf("%d",result);
	result = ft_str_is_uppercase("");
	printf("%d",result);

}
