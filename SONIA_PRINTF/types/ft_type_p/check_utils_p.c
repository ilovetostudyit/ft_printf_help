#include "../../ft_printf.h"

void    fill_with_zeros(t_param *param, t_buf *buf, int len)
{
    if (param->precision > len - 2)
			ft_buf_add_s(buf, ft_memnew(param->precision - len + 2, '0'), 0);
}