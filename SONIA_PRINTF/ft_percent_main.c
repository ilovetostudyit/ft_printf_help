#include "ft_printf.h"

static void		ft_type_small_alpha(va_list *ap, char **str, t_param *param, t_buf *buf)
{
//	if (**str == 'c' && list.length == 'l')
//		ft_c_up(list, (wchar_t)va_arg(ap, wchar_t), buf);
//	else if (**str == 's' && list.length == 'l')
//		ft_s_up(list, (wchar_t *)va_arg(ap, wchar_t *), buf);
//	else if (**str == 'u')
//		ft_u(list, ap, buf);
//	else if (**str == 'x')
//		ft_x(list, ap, buf);
//	else if (**str == 'f')
//		ft_f(list, ap, buf);
//	else if (**str == 'c')
//		ft_c(list, (char)va_arg(ap, int), buf);
//	else if (**str == 's')
//		ft_s(list, (char *)va_arg(ap, char *), buf);
//	else if (**str == 'o')
//		ft_o(list, ap, buf);
//	else if (**str == 'p')
//		ft_p(list, va_arg(ap, void *), buf);
//	else if (**str == 'd' || **str == 'i')
//		ft_d(list, ap, buf);
//	else if (**str)
//		ft_c(list, **str, buf);
}
static void		ft_type_big_alpha(va_list *ap, char **str, t_param *param, t_buf *buf)
{
//	if (**str == 'D')
//		ft_d_up(list, ap, buf);
//	else if (**str == 'U')
//		ft_u_up(list, ap, buf);
//	else if (**str == 'X')
//		ft_x_up(list, ap, buf);
//	else if (**str == 'F')
//		ft_f_up(list, ap, buf);
//	else if (**str == 'O')
//		ft_o_up(list, ap, buf);
//	else if (**str == 'C')
//		ft_c_up(list, (wchar_t)va_arg(ap, wchar_t), buf);
//	else if (**str == 'S')
//		ft_s_up(list, (wchar_t *)va_arg(ap, wchar_t *), buf);
//	else if (**str)
//		ft_c(list, **str, buf);
}
static void		ft_type_symbol(va_list *ap, char **str, t_param *param, t_buf *buf)
{
//	else if (**str == '%')
//		ft_prcnt(list, buf);
//	else if (**str)
//		ft_c(list, **str, buf);
}
static void		ft_type(va_list *ap, char **str, t_param *param, t_buf *buf)
{
//	if (**str > .. && **str < ..)
//		ft_type_small_alpha(ap, str, param, buf);
//	else if (**str > .. && **str < ..)
//		ft_type_big_alpha(ap, str, param, buf);
//	else (**str == '%')
//		ft_type_symbol(ap, str, param, buf);
}

void ft_percent_main(t_buf *buf, t_param *param, char **str, va_list *ap)
{
	*str = *str + 1;
	ft_add_new_param(param, str, ap);
	ft_type(ap, str, param, buf);
    ft_printf("Обрабатываем проценты");
}
