#include "../../ft_printf.h"

void    s_ap_check(t_buf *buf, char *ap)
{
    if (ap != NULL)
			ft_buf_add_s(buf, ap, 1);
	else
			ft_buf_add_s(buf, "(null)", 1);
}

void    s_width_check(t_param param, char *ap, int tmp, t_buf *buf)
{
    if (param.width > tmp && param.zero == 0 && ap != NULL)
			ft_buf_add_s(buf, ft_memnew(param.width - tmp, ' '), 1);
	else if (param.width > tmp && param.zero == 1)
			ft_buf_add_s(buf, ft_memnew(param.width - tmp, '0'), 1);
}