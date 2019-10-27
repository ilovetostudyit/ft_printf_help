#include "../../ft_printf.h"

static void		just_print(t_param param, char *i, t_buf *buf)
{
	param.plus == 1 && *i != '-' ? ft_print_else(buf, '+') : 0;
	*i == '-' ? ft_print_else(buf, '-') : 0;
	ft_buf_add_s(buf, i, 0, 1);
	param.hash == 1 && param.precision == 0 ? ft_print_else(buf, '.') : 0;
}

static void		minus_pos(t_param param, char *i, int tmp, t_buf *buf)
{
	if (param.space == 1 && param.plus == 0 && *i != '-')
		ft_print_else(buf, ' ');
	param.plus == 1 && *i != '-' ? ft_print_else(buf, '+') : 0;
	ft_buf_add_s(buf, i, 0, 1);
	param.hash == 1 && param.precision == 0 ? ft_print_else(buf, '.') : 0;
	if (param.width > tmp + (*i != '-' && (param.plus == 1 || param.space == 1)))
		ft_buf_add_s(buf, ft_memnew(param.width - tmp - (*i != '-' &&
			(param.plus == 1 || param.space == 1)), ' '), 0, 1);
}

static void		minus_neg(t_param param, char *i, int tmp, t_buf *buf)
{
	if (param.width > tmp + (*i != '-' && (param.plus == 1 || param.space == 1)))
	{
		if (param.zero == 0)
		{
			ft_buf_add_s(buf, ft_memnew(param.width - tmp - (*i != '-' &&
				(param.plus == 1 || param.space == 1)), ' '), 0, 1);
			((param.space == 1 && *i != '-') || (param.space == 1
						&& param.plus == 0)) ? ft_print_else(buf, ' ') : 0;
			param.plus == 1 && *i != '-' ? ft_print_else(buf, '+') : 0;
		}
		else
		{
			((param.space == 1 && *i != '-') || (param.space == 1 &&
			param.plus == 0)) ? ft_print_else(buf, ' ') : 0;
			param.plus == 1 && *i != '-' ? ft_print_else(buf, '+') : 0;
			*i == '-' ? ft_print_else(buf, '-') : 0;
			*i == '-' ? i++ : 0;
			ft_buf_add_s(buf, ft_memnew(param.width - tmp -
				(param.plus || *i == '-') - param.space, '0'), 0, 1);
		}
		ft_buf_add_s(buf, i, 0, 1);
		param.hash == 1 && param.precision == 0 ? ft_print_else(buf, '.') : 0;
	}
	else
		just_print(param, i, buf);
}

static void		ft_print_f(t_param param, char *i, t_buf *buf)
{
	int	tmp;

	tmp = ft_strlen(i);
	if (param.precision == 0 && param.hash == 1)
		tmp += 1;
	if (param.minus == 0)
		minus_neg(param, i, tmp, buf);
	if (param.minus == 1)
		minus_pos(param, i, tmp, buf);
}

void			ft_type_f(t_param param, va_list ap, t_buf *buf)
{
	param.precision == -1 ? param.precision = 6 : 0;
	param.precision == -2 ? param.precision = 0 : 0;
	if (param.length == 'L')
		ft_print_f(param,
				ft_float_f(va_arg(ap, long double), param.precision), buf);
	else
		ft_print_f(param,
				ft_float_f(va_arg(ap, double), param.precision), buf);
}
