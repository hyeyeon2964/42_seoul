/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:14:38 by hmyoung           #+#    #+#             */
/*   Updated: 2020/07/14 20:55:35 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					find_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned	int		ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned	int		dest_i;
	unsigned	int		src_i;
	int					i;
	int					j;

	i = 0;
	j = find_len(dest);
	dest_i = find_len(dest);
	src_i = find_len(src);
	while (src[i] != '\0' && i + 1 + dest_i < size)
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	if (size < dest_i)
		return (src_i + size);
	else
		return (dest_i + src_i);
}
