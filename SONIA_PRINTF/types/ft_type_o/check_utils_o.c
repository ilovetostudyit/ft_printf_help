#include "../../ft_printf.h"

void    o_hash_check(t_param param, t_buf *buf)
{
    if (param.hash == 1 && param.precision < 1)
			ft_print_else(buf, '0');
}

void    o_minus_check(t_param *param, t_buf *buf, int tmp)
{
    if (param->minus == 1 && param->width - param->hash > tmp)
		ft_buf_add_s(buf, ft_memnew(param->width - param->hash - tmp, ' '), 0);
}