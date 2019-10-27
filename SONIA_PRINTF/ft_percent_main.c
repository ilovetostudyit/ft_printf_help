#include "ft_printf.h"

static void		ft_type_cont(va_list ap, char **str, t_param list, t_buf *buf)
{
	if (**str == 'D')
		ft_type_d_up(list, ap, buf);
	else if (**str == 'u')
		ft_type_u(list, ap, buf);
	else if (**str == 'U')
		ft_type_u_up(list, ap, buf);
	else if (**str == 'x')
		ft_type_x(list, ap, buf);
	else if (**str == 'X')
		ft_type_x_up(list, ap, buf);
	else if (**str == '%')
		ft_type_percent(list, buf);
	else if (**str == 'f')
		ft_type_f(list, ap, buf);
	else if (**str == 'F')
		ft_type_f_up(list, ap, buf);
	else if (**str)
		ft_type_c(list, **str, buf);
}

static void		ft_type(va_list ap, char **str, t_param list, t_buf *buf)
{
	if (**str == 'C' || (**str == 'c' && list.length == 'l'))
		ft_type_c_up(list, (wchar_t)va_arg(ap, wchar_t), buf);
	else if (**str == 'c')
		ft_type_c(list, (char)va_arg(ap, int), buf);
	else if (**str == 'S' || (**str == 's' && list.length == 'l'))
		ft_type_s_up(list, (wchar_t *)va_arg(ap, wchar_t *), buf);
	else if (**str == 's')
		ft_type_s(list, (char *)va_arg(ap, char *), buf);
	else if (**str == 'o')
		ft_type_o(list, ap, buf);
	else if (**str == 'O')
		ft_type_o_up(list, ap, buf);
	else if (**str == 'p')
		ft_type_p(list, va_arg(ap, void *), buf);
	else if (**str == 'd' || **str == 'i')
		ft_type_d(list, ap, buf);
	else
		ft_type_cont(ap, str, list, buf);
}

void ft_percent_main(t_buf *buf, t_param param, char **str, va_list ap)
{
	////printf("%s\n", "Обрабатываем проценты");
	*str = *str + 1;
	ft_param_fill(&param, str, ap);
	ft_type(ap, str, param, buf);
}
