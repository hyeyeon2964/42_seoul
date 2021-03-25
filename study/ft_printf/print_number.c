
#include "ft_printf.h"

char *before_print_d(int num)
{
	int len;
	char *blank;

	blank = "";
	len = ft_strlen(ft_itoa(num));
	if (g_info.width == 0 && g_info.precision == -1)
		return blank;
	if (len > g_info.width)
		g_info.width = 0;
	if (len > g_info.precision)
		g_info.precision = -1;
	if (g_info.precision > g_info.width)
		blank = make_flag(g_info.precision - len, '0');
	else if ((g_info.width > g_info.precision)
			&& g_info.zero == 1)
		 blank = make_flag(g_info.width - len, '0');
	else if (g_info.width > g_info.precision)
		blank = make_flag(g_info.width - len, ' ');
	return (blank);
}

void print_d(va_list ap)
{
	int num;
	char *str;
	char *blank;

	if (g_info.type == 'd' || g_info.type == 'i')
		num = va_arg(ap, int);
	else
		num = va_arg(ap, unsigned int);
	blank = before_print_d(num);
	str = ft_itoa(num);
	if (g_info.precision == -1 && g_info.width == 0)
	{
		print_str(str);
		return ;
	}
	if (g_info.minus == 1)
		str = ft_strjoin(str, blank);
	else
		str = ft_strjoin(blank, str);
	print_str(str);
}
