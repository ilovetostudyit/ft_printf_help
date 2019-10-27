#include "ft_printf.h"

static void		ft_type_cont(va_list ap, char **str, t_param param, t_buf *buf)
{
	if (**str == 'u')
		ft_type_u(param, ap, buf);
	else if (**str == 'x')
		ft_type_x(param, ap, buf);
	else if (**str == 'X')
		ft_type_x_up(param, ap, buf);
	else if (**str == '%')
		ft_type_percent(param, buf);
	else if (**str == 'f')
		ft_type_f(param, ap, buf);
	else if (**str)
		ft_type_c(param, **str, buf);
}

static void		ft_type(va_list ap, char **str, t_param param, t_buf *buf)
{
	if (**str == 'c')
		ft_type_c(param, (char)va_arg(ap, int), buf);
	else if (**str == 's')
		ft_type_s(param, (char *)va_arg(ap, char *), buf);
	else if (**str == 'o')
		ft_type_o(param, ap, buf);
	else if (**str == 'p')
		ft_type_p(param, va_arg(ap, void *), buf);
	else if (**str == 'd' || **str == 'i')
		ft_type_d(param, ap, buf);
	else
		ft_type_cont(ap, str, param, buf);
}

void ft_percent_main(t_buf *buf, t_param param, char **str, va_list ap)
{
	////printf("%s\n", "Обрабатываем проценты");
	*str = *str + 1;
	ft_param_fill(&param, str, ap);
	ft_type(ap, str, param, buf);
}
