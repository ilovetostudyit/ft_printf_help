#include "../../ft_printf.h"

void		ft_type_s_prec_pos(t_param param, char *ap, int tmp, t_buf *buf)
{
		if (ap != NULL)
			ft_buf_add_ns(buf, ap, tmp < param.precision ? tmp : param.precision, 1);
		else
			ft_buf_add_ns(buf, "(null)", param.precision, 1);
		if (param.width > (tmp < param.precision ? tmp : param.precision) && param.zero == 1)
			ft_buf_add_s(buf, ft_memnew(param.width - (tmp < param.precision ? tmp : param.precision) - (tmp == 0 ? param.precision : 0), '0'), 1);
		else if (param.width > (tmp < param.precision ? tmp : param.precision) && ap != NULL)
			ft_buf_add_s(buf, ft_memnew(param.width - (tmp < param.precision ? tmp : param.precision), ' '), 1);
}


void		ft_type_s_minus(t_param param, char *ap, int tmp, t_buf *buf)
{
	if (param.width > (tmp < param.precision ? tmp : param.precision) && param.zero == 1)
		ft_buf_add_s(buf, ft_memnew(param.width - (tmp < param.precision ? tmp : param.precision) - (tmp == 0 ? param.precision : 0), '0'), 1);
	else if (param.width > (tmp < param.precision ? tmp : param.precision) && ap != NULL)
		ft_buf_add_s(buf, ft_memnew(param.width - (tmp < param.precision ? tmp : param.precision), ' '), 1);
	if (ap != NULL)
		ft_buf_add_ns(buf, ap, tmp < param.precision ? tmp : param.precision, 1);
	else
		ft_buf_add_ns(buf, "(null)", param.precision, 1);
}

void		ft_type_s_prec_neg(t_param param, char *ap, int tmp, t_buf *buf)
{
	if (param.minus == 0)
	{
		s_width_check(param, ap, tmp, buf);
		s_ap_check(buf, ap);
	}
	else
	{
		s_ap_check(buf, ap);
		s_width_check(param, ap, tmp, buf);
	}
}
