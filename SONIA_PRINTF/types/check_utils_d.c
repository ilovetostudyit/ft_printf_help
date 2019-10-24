#include "../ft_printf.h"

void ft_tire_check(char *str, t_buf *buf)
{
    if (*str == '-')
		ft_print_else(buf, '-');
}

void ft_space_check(char *str, t_param *param, t_buf *buf)
{
    //printf("%s\n", "проверка пробелов");
    if (param->space == 1 && param->plus == 0 && *str != '-')
		ft_print_else(buf, ' ');
	else
		param->space = 0;
}

void ft_plus_check(char *str, t_param *param, t_buf *buf)
{
    if (param->plus == 1 && *str != '-')
		ft_print_else(buf, '+');
}