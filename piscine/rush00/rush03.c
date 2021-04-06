/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 09:35:16 by hmyoung           #+#    #+#             */
/*   Updated: 2020/07/05 10:04:15 by hmyoung          ###   ########.fr       */
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
			if ((i == 1 && j == 1) || (j == height && i == 1))
				ft_putchar('A');
			else if ((i == width && j == 1) || (j == height && i == width))
				ft_putchar('C');
			else if ((i == 1 || i == width) && (j != 1 || j != height))
				ft_putchar('B');
			else if ((i != 1 || i != width) && (j == 1 || j == height))
				ft_putchar('B');
			else
				ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		i = 1;
		j++;
	}
}
