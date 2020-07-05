/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhokim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 11:01:34 by junhokim          #+#    #+#             */
/*   Updated: 2020/07/05 11:14:20 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int width, int height)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (j <= height)
	{
		while (i <= width)
		{
			if (i == 1)
			{
				if (j == 1)
					ft_putchar('/');
				else if (j == height)
					ft_putchar('\\');
				else
					ft_putchar('*');
			}
			else if (i == width)
			{
				if(j == 1)
					ft_putchar('\\');
				else if (j == height)
					ft_putchar('/');
				else
					ft_putchat('*');
			}
			else
			{
				if (i == 1 || j == 1)
					ft_putchar('*');
				else
					ft_putchar(' ');
			}
		}
	}
};
