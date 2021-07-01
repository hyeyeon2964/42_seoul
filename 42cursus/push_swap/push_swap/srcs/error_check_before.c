/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_before.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jung-lee <jung-lee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:49:05 by jung-lee          #+#    #+#             */
/*   Updated: 2021/06/29 16:37:02 by jung-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				write_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int				error_over_int(const char *str)
{
	long long	n;

	n = ft_atoi(str);
	if (n > 2147483647)
		return (1);
	if (n < -2147483648)
		return (1);
	return (0);
}

int				error_not_number(const char *str)
{
	int			i;

	i = 0;
	while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == ' ' ||
			str[i] == '\n' || str[i] == '\r' || str[i] == '\v'))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && '0' <= str[i] && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		return (0);
	return (1);
}

int				error_check_before(int argc, char **argv)
{
	int			i;

	i = argc - 1;
	if (i == 0)
		exit(0);
	while (0 < i)
	{
		if (error_over_int(argv[i]))
			return (1);
		if (error_not_number(argv[i]))
			return (1);
		i--;
	}
	return (0);
}
