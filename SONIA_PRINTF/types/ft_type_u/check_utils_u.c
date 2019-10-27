#include "../../ft_printf.h"

void    u_prec_tmp_check(t_param param, t_buf *buf, int tmp)
{
    if (param.precision > tmp)
		ft_buf_add_s(buf, ft_memnew(param.precision - tmp, '0'), 0, 1);
}