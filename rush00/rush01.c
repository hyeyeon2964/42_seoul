/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhokim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 11:01:34 by junhokim          #+#    #+#             */
/*   Updated: 2020/07/05 13:42:57 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int width, int height)
{
	int i;
	int j;

	j = 0;
	while (j++ < height)
	{
		i = 0;
		while (i++ < width)
		{
			if (i == 1 || i == width)
			{
				if ((i == 1 && j == 1) || (i != 1 && j != 1 && j == height))
					ft_putchar('/');
				else if ((i == 1 && j == height) || (i == width && j == 1))
					ft_putchar('\\');
				else
					ft_putchar('*');
			}
			else if ((i != 1 && i != width) && (j == 1 || j == height))
				ft_putchar('*');
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
