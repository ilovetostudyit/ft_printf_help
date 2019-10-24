#include "../../ft_printf.h"

void		ft_type_s_prec_pos(t_param param, char *ap, int tmp, t_buf *buf)
{
		s_pres_ap_check(param, ap, tmp, buf);
		s_pres_width_check(param,ap,tmp,buf);
}


void		ft_type_s_minus(t_param param, char *ap, int tmp, t_buf *buf)
{
	s_pres_width_check(param,ap,tmp,buf);
	s_pres_ap_check(param, ap, tmp, buf);
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
