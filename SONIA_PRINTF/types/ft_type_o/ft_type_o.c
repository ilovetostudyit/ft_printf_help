#include "../../ft_printf.h"

static int	ft_type_o_l_ll_check(t_param param, va_list ap, t_buf *buf)
{
	//printf("%s\n", "		Обрабатываем, флаг 1");
	if (param.length == 0)
		ft_print_o(param,
				ft_itoa_base_ll((unsigned int)va_arg(ap, int), 8), buf);
	else if (param.length == 'l')
		ft_print_o(param,
				ft_itoa_base_ll((unsigned long)va_arg(ap, int), 8), buf);
	else if (param.length == 'l' + 'l')
		ft_print_o(param,
			ft_itoa_base_ll((unsigned long long)va_arg(ap, long long), 8), buf);
	else
		return(0);	
	return(1);
}

static int	ft_type_o_h_hh_check(t_param param, va_list ap, t_buf *buf)
{
	////printf("%s\n", "		Обрабатываем, флаг 2");
	if (param.length == 'h')
		ft_print_o(param,
				ft_itoa_base_ll((unsigned short)va_arg(ap, int), 8), buf);
	else if (param.length == 'h' + 'h')
		ft_print_o(param,
				ft_itoa_base_ll((unsigned char)va_arg(ap, int), 8), buf);
	else
		return(0);	
	return(1);
}

static int ft_type_o_j_z_check(t_param param, va_list ap, t_buf *buf)
{
	////printf("%s\n", "		Обрабатываем, флаг 3");
	if (param.length == 'j')
		ft_print_o(param,
				ft_itoa_base_ll((uintmax_t)va_arg(ap, uintmax_t), 8), buf);
	else if (param.length == 'z')
		ft_print_o(param, ft_itoa_base_ll((size_t)va_arg(ap, size_t), 8), buf);
	else
		return(0);
	return(1);
}

void				ft_type_o(t_param param, va_list ap, t_buf *buf)
{
	//printf("%s\n", "		Обрабатываем, флаг o");
	if (!(ft_type_o_l_ll_check(param, ap, buf)))
		if (!(ft_type_o_h_hh_check(param, ap, buf)))
			ft_type_o_j_z_check(param, ap, buf);
}
