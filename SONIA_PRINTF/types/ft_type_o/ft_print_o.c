#include "../../ft_printf.h"

static void			prec_neg(char *str, t_param param, t_buf *buf)
{
	int tmp;
	//printf("%s\n", "		Обрабатываем, флаг 5");
	tmp = ft_strlen(str);
    o_minus_zero(&param, buf, tmp);
	param.hash == 1 ? ft_print_else(buf, '0') : 0;
	ft_buf_add_s(buf, str, 0, 0);
    o_minus_check(&param, buf, tmp);
}

static void			minus_neg(char *str, t_param param, t_buf *buf)
{
    int tmp;
	//printf("%s\n", "		Обрабатываем, флаг 4");
	tmp = ft_strlen(str);
    if (param.width > param.precision && param.width > tmp)
    {
        if (param.zero == 1 && param.precision <= -1)
            ft_buf_add_s(buf, ft_memnew(param.width -
			(param.precision > tmp ? param.precision : tmp) -
				(param.hash == 1 && param.precision <= tmp), '0'), 0, 0);
        else 
        {
            ft_buf_add_s(buf, ft_memnew(param.width -
			(param.precision > tmp ? param.precision : tmp) -
				(param.hash == 1 && param.precision <= tmp), ' '), 0, 0);
        }
    }
	if (tmp >= param.precision && param.hash == 1)
		ft_print_else(buf, '0');
	//printf("%s\n", "		Обрабатываем, флаг o");
	o_prec_check(param, buf, tmp);
	tmp != 0 ? ft_buf_add_s(buf, str, 0, 0) : 0;
}

static void			prec_pos(char *str, t_param param, t_buf *buf)
{
	int tmp;
	//printf("%s\n", "		Обрабатываем, флаг 3");
	tmp = ft_strlen(str);
	if (tmp >= param.precision && param.hash == 1)
		ft_print_else(buf, '0');
	o_prec_check(param, buf, tmp);
	tmp != 0 ? ft_buf_add_s(buf, str, 0, 0) : 0;
	if (param.width > param.precision && param.width > tmp)
		ft_buf_add_s(buf, ft_memnew(param.width -
			(param.precision > tmp ? param.precision : tmp) -
				(param.hash == 1 && param.precision <= tmp), ' '), 0, 0);
}

void		ft_print_o(t_param param, char *str, t_buf *buf)
{
	//printf("%s\n", "		Обрабатываем, флаг 2");
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