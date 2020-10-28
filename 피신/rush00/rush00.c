/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 18:26:46 by milee             #+#    #+#             */
/*   Updated: 2020/07/04 19:14:12 by milee            ###   ########.fr       */
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
			if ((i == 1 || i == width) && (j == 1 || j == height))
				ft_putchar('o');
			else if ((i == 1 || i == width) && (j != 1 || j != height))
				ft_putchar('|');
			else if ((i != 1 || i != width) && (j == 1 || j == height))
				ft_putchar('-');
			else
				ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		i = 1;
		j++;
	}
}
