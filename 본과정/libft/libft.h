/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 19:57:26 by hmyoung           #+#    #+#             */
/*   Updated: 2020/10/28 21:46:57 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

void	*ft_memset(void *ptr, int value, size_t num);
void	*ft_bzero(void *ptr, size_t num);
void	*ft_memcpy(void *des, const void *src, size_t num);
void	*ft_memccpy(void *des, const void *src, int c, size_t num);
void	*ft_memmove(void *des, const void *src, size_t num);
void	*ft_memchr(void *ptr, int value, size_t num);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
#endif
