/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 19:20:18 by hmyoung           #+#    #+#             */
/*   Updated: 2020/10/07 19:20:21 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int		ft_strlen(const char *s){
	int size;

	size = 0;
	while(*s != '\0'){
		size++;
		s++;
	}
	return size;
}

char	*strrchr(const char *s, int ch)
{
	int size;
	char *answer = s;
	size  = ft_strlen(s);
	printf("%d", size);

	return s;
}

#include <stdio.h>
int main(void){
	char s1[30] = "A Garden Diary";
	char *ptr = strrchr(s1, 'a');
	printf("%s \n", ptr);
	return 0;
}
