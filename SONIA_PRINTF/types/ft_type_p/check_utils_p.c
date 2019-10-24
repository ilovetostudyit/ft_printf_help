#include "../../ft_printf.h"

void    fill_with_zeros(t_param *param, t_buf *buf, int len)
{
    if (param->precision > len - 2)
			ft_buf_add_s(buf, ft_memnew(param->precision - len + 2, '0'), 0);
}

void    p_precision_check(t_param *param, t_buf *buf, int len)
{
    if (param->width > param->precision && param->width > len)
        {
            if (param->precision > len - 2)
                ft_buf_add_s(buf,
						ft_memnew(param->width - param->precision - 2, ' '), 0);
            else
                ft_buf_add_s(buf, 
                    ft_memnew(param->width - len, ' '), 0);
        }
}