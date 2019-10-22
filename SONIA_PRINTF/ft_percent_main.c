#include "ft_printf.h"

static void		ft_type_small_alpha(va_list *ap, char **str, t_param *param, t_buf *buf)
{
	printf("%s\n", "		Обрабатываем, если маленькая буква");
	if (**str == 'c' && list.length == 'l')
		ft_type_c_up(list, (wchar_t)va_arg(ap, wchar_t), buf);
	else if (**str == 's' && list.length == 'l')
		ft_type_s_up(list, (wchar_t *)va_arg(ap, wchar_t *), buf);
	else if (**str == 'u')
		ft_type_u(list, ap, buf);
	else if (**str == 'x')
		ft_type_x(list, ap, buf);
	else if (**str == 'c')
		ft_type_c(list, (char)va_arg(ap, int), buf);
	else if (**str == 's')
		ft_type_s(list, (char *)va_arg(ap, char *), buf);
	else if (**str == 'o')
		ft_type_o(list, ap, buf);
	else if (**str == 'f')
		ft_type_f(list, ap, buf);
	else if (**str == 'p')
		ft_type_p(list, va_arg(ap, void *), buf);
	else if (**str == 'd' || **str == 'i')
		ft_type_d(list, ap, buf);
	else if (**str)
		ft_type_c(list, **str, buf);
	
}
static void		ft_type_big_alpha(va_list *ap, char **str, t_param *param, t_buf *buf)
{
	printf("%s\n", "		Обрабатываем, если большая буква");
	if (**str == 'C')
		ft_type_c_up(list, (wchar_t)va_arg(ap, wchar_t), buf);
	else if (**str == 'S')
		ft_type_s_up(list, (wchar_t *)va_arg(ap, wchar_t *), buf);
	else if (**str == 'D')
		ft_type_d_up(list, ap, buf);
	else if (**str == 'U')
		ft_type_u_up(list, ap, buf);
	else if (**str == 'X')
		ft_type_x_up(list, ap, buf);
	else if (**str == 'F')
		ft_type_f_up(list, ap, buf);
	else if (**str == 'O')
		ft_type_o_up(list, ap, buf);
	else if (**str)
		ft_type_c(list, **str, buf);
	
}
static void		ft_type_symbol(va_list *ap, char **str, t_param *param, t_buf *buf)
{
	printf("%s\n", "		Обрабатываем, если символ");
	if (**str == '%')
		ft_type_percent(list, buf);
	else if (**str)
		ft_type_c(list, **str, buf);
}
static void		ft_type_selector(va_list *ap, char **str, t_param *param, t_buf *buf)
{
	printf("%s\n", "	Выбираем тип (большая буква, маленькая, символ)");
}

void ft_percent_main(t_buf *buf, t_param *param, char **str, va_list *ap)
{
	printf("%s\n", "Обрабатываем проценты");
	if (*str && *str + 1)
	{
		*str = *str + 1;
		ft_add_new_param(param, str, ap); //собрать
		ft_type_selector(ap, str, param, buf); // cобрать
	}
}
