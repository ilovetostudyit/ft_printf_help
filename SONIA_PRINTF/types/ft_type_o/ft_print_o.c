#include "../../ft_printf.h"

static void			prec_neg(char *str, t_param param, t_buf *buf)
{
	int tmp;

	tmp = ft_strlen(str);
    if (param.minus == 0 && param.width - param.hash > tmp)
    {
	    if (param.zero == 1)
		    ft_buf_add_s(buf, ft_memnew(param.width - param.hash - tmp, '0'), 0);
	    else if (param.zero == 0)
		    ft_buf_add_s(buf, ft_memnew(param.width - param.hash - tmp, ' '), 0);
    }
	param.hash == 1 ? ft_print_else(buf, '0') : 0;
	ft_buf_add_s(buf, str, 0);
    o_minus_check(&param, buf, tmp);
}

static void			minus_neg(char *str, t_param param, t_buf *buf)
{
    int tmp;

	tmp = ft_strlen(str);
    if (param.width > param.precision && param.width > tmp)
    {
        if (param.zero == 1 && param.precision <= -1)
            ft_buf_add_s(buf, ft_memnew(param.width -
			(param.precision > tmp ? param.precision : tmp) -
				(param.hash == 1 && param.precision <= tmp), '0'), 0);
        else 
        {
            ft_buf_add_s(buf, ft_memnew(param.width -
			(param.precision > tmp ? param.precision : tmp) -
				(param.hash == 1 && param.precision <= tmp), ' '), 0);
        }
    }
	if (tmp >= param.precision && param.hash == 1)
		ft_print_else(buf, '0');
	if (param.precision > tmp)
		ft_buf_add_s(buf, ft_memnew(param.precision - tmp, '0'), 0);
	tmp != 0 ? ft_buf_add_s(buf, str, 0) : 0;
}

static void			prec_pos(char *str, t_param param, t_buf *buf)
{
	int tmp;

	tmp = ft_strlen(str);
	if (tmp >= param.precision && param.hash == 1)
		ft_print_else(buf, '0');
	if (param.precision > tmp)
		ft_buf_add_s(buf, ft_memnew(param.precision - tmp, '0'), 0);
	tmp != 0 ? ft_buf_add_s(buf, str, 0) : 0;
	if (param.width > param.precision && param.width > tmp)
		ft_buf_add_s(buf, ft_memnew(param.width -
			(param.precision > tmp ? param.precision : tmp) -
				(param.hash == 1 && param.precision <= tmp), ' '), 0);
}

void		ft_print_o(t_param param, char *str, t_buf *buf)
{
    if (*str != '0')
	{
		if (param.precision == -1)
			prec_neg(str, param, buf);
		else if (param.minus == 0)
            minus_neg(str, param, buf);
        else
			prec_pos(str, param, buf);
	}
	else
	{
		if (param.precision == -1)
			prec_neg_null(str, param, buf);
		else
			prec_pos_null(str, param, buf);
	}
}