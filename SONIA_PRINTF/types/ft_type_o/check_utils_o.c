#include "../../ft_printf.h"

void    o_hash_check(t_param *param, t_buf *buf)
{
    if (param->hash == 1 && param->precision < 1)
			ft_print_else(buf, '0');
}

void    o_minus_check(t_param *param, t_buf *buf, int tmp)
{
    if (param->minus == 1 && param->width - param->hash > tmp)
		ft_buf_add_s(buf, ft_memnew(param->width - param->hash - tmp, ' '), 0);
}

void    o_minus_zero(t_param *param, t_buf *buf, int tmp)
{
    if (param->minus == 0 && param->width - param->hash > tmp)
	{
		if (param->zero == 1)
			ft_buf_add_s(buf, ft_memnew(param->width - param->hash - tmp, '0'), 0);
		else if (param->zero == 0)
			ft_buf_add_s(buf, ft_memnew(param->width - param->hash - tmp, ' '), 0);
	}
}

void    o_prec_check(t_param *param, t_buf *buf, int tmp)
{
    if (param->precision > 0)
			ft_buf_add_s(buf, ft_memnew(param->precision - tmp, '0'), 0);
}
