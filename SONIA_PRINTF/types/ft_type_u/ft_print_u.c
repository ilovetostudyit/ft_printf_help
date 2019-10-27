#include "../../ft_printf.h"

static void	minus_pos(char *i, t_param param, int tmp, t_buf *buf)
{
	u_prec_tmp_check(param, buf, tmp);
	ft_buf_add_s(buf, i, 0, 1);
    if (param.width > param.precision && param.width > tmp)
    {
        if (param.zero == 1)
            ft_buf_add_s(buf, ft_memnew(param.width - param.space -
				(param.precision > tmp ? param.precision : tmp), '0'), 0, 1);
        ft_buf_add_s(buf, ft_memnew(param.width - param.space -
			(param.precision > tmp ? param.precision : tmp), ' '), 0, 1);
    }
}

static void	prec_neg(char *i, t_param param, int tmp, t_buf *buf)
{
    if (param.minus == 0 && param.width > tmp)
    {
        if (param.zero == 0)
            ft_buf_add_s(buf, ft_memnew(param.width - tmp, ' '), 0, 1);
        else if (param.zero == 1)
            ft_buf_add_s(buf, ft_memnew(param.width - tmp, '0'), 0, 1);
    }
	ft_buf_add_s(buf, i, 0, 1);
	if (param.minus == 1 && param.width > tmp)
		ft_buf_add_s(buf, ft_memnew(param.width - tmp, ' '), 0, 1);
}

static void	prec_pos(char *i, t_param param, int tmp, t_buf *buf)
{
	*i == '0' && param.precision == 0 ? tmp -= 1 : 0;
    if (param.width > param.precision && param.width > tmp)
    {
        ft_buf_add_s(buf, ft_memnew(param.width - param.space -
			(param.precision > tmp ? param.precision : tmp), ' '), 0, 1);
        if (param.zero == 1)
            ft_buf_add_s(buf, ft_memnew(param.width - param.space -
			(param.precision > tmp ? param.precision : tmp), '0'), 0, 1);
    }
	u_prec_tmp_check(param, buf, tmp);
	*i == '0' && param.precision == 0 ? NULL : ft_buf_add_s(buf, i, 0, 1);
}

void		ft_print_u(t_param param, char *ap, t_buf *buf)
{
    param.precision > -1 ? param.zero = 0 : 0;
	if (param.precision == -1)
		prec_neg(ap, param, ft_strlen(ap), buf);
	else if (param.minus == 0)
		prec_pos(ap, param, ft_strlen(ap), buf);
	else if (param.minus == 1)
		minus_pos(ap, param, ft_strlen(ap), buf);
}