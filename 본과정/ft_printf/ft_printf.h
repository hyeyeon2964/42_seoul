/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:47:53 by hmyoung           #+#    #+#             */
/*   Updated: 2021/03/09 20:49:46 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct	s_info
{
	int			zero;
	int			minus;
	int			width;
	int			dot;
	int			star;
	int			precision;
	char		type;
}				t_info;
t_info			g_info;

int				ft_printf(const char *format, ...);
int				option_check(const char *format, int i);
int				finish_check(const char *format, int i);
int				integer_len(int num);

#endif
