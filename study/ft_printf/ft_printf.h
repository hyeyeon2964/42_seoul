/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmyoung <hmyoung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:47:53 by hmyoung           #+#    #+#             */
/*   Updated: 2021/03/21 17:23:57 by hmyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_info
{
	int			zero;
	int			minus;
	int			width;
	int			dot;
	int			len;
	int			width_star;
	int			precision_star;
	int			precision;
	int			result;
	char		type;
}				t_info;
t_info			g_info;

int				ft_printf(const char *format, ...);
int				option_check(const char *format, int i);
int				finish_check(const char *format, int i);
int				integer_len(int num);
void			struct_reset(void);
void			print_result(va_list ap);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);

#endif
