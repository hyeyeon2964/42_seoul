
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

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
void			save_option(va_list ap);
void			print_result(va_list ap);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_isspace(char str);
int				ft_atoi(const char *str);
size_t			get_len(int n);
char			*ft_itoa(int n);
void			print_str(char *str);
char 			*make_flag(int width, char c);
void 			print_s(va_list ap);
void 			print_c(va_list ap);
void 			print_d(va_list ap);
void			print_x(va_list ap);
void			print_p(va_list ap);
void			print_per(void);
char			*ft_strdup(const char *s);
char			*ft_itoh(long long n);
#endif
