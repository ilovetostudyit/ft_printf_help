#include "../../ft_printf.h"

void	minus_neg_null(t_param param, char *str, int tmp, t_buf *buf)
{
	if ((param.width - (param.precision > tmp ? param.precision : tmp) -
										param.hash) >= 0 && param.zero != 1)
		ft_buf_add_s(buf, ft_memnew(param.width - (param.precision > tmp ?
				param.precision : tmp) -
					(param.hash == 1 && param.precision == -1), ' '), 0);
	if (param.precision == -1)
		ft_buf_add_s(buf, "0", 1);
	if ((param.width - (param.precision > tmp ? param.precision : tmp) -
										param.hash) > 0 && param.zero == 1)
		ft_buf_add_s(buf, ft_memnew(param.width - tmp -
		(param.hash == 1 && param.precision == -1), '0'), 0);
	if (param.precision > tmp)
		ft_buf_add_s(buf, ft_memnew(param.precision - tmp, '0'), 0);
}

void	minus_pos_null(t_param param, char *str, int tmp, t_buf *buf)
{
	if (param.precision == -1)
		ft_buf_add_s(buf, "0", 1);
	if (param.precision > tmp)
		ft_buf_add_s(buf, ft_memnew(param.precision - tmp, '0'), 0);
	if ((param.width - (param.precision > tmp ? param.precision : tmp) -
										param.hash) >= 0 && param.zero != 1)
		ft_buf_add_s(buf,
		ft_memnew(param.width - (param.precision > tmp ? param.precision : tmp)
					- (param.hash == 1 && param.precision == -1), ' '), 0);
}

static void	minus_neg(t_param param, char *str, int tmp, t_buf *buf)
{
	if ((param.width - (param.precision > tmp ? param.precision : tmp) -
											param.hash) >= 0 && param.zero != 1)
		ft_buf_add_s(buf, ft_memnew(param.width - (param.precision > tmp ?
		param.precision : tmp) - param.hash, ' '), 0);
	if (param.hash != 0)
		ft_buf_add_s(buf, "0x", 1);
	if ((param.width - (param.precision > tmp ? param.precision : tmp) -
											param.hash) >= 0 && param.zero == 1)
		ft_buf_add_s(buf, ft_memnew(param.width - tmp -
		param.hash, '0'), 0);
	if (param.precision > tmp)
		ft_buf_add_s(buf, ft_memnew(param.precision - tmp, '0'), 0);
	ft_buf_add_s(buf, str, 0);
}

static void	minus_pos(t_param param, char *str, int tmp, t_buf *buf)
{
	if (param.hash != 0)
		ft_buf_add_s(buf, "0x", 1);
	if (param.precision > tmp)
		ft_buf_add_s(buf, ft_memnew(param.precision - tmp, '0'), 0);
	ft_buf_add_s(buf, str, 0);
	if ((param.width - (param.precision > tmp ? param.precision : tmp) -
											param.hash) >= 0 && param.zero != 1)
		ft_buf_add_s(buf, ft_memnew(param.width - (param.precision > tmp ?
		param.precision : tmp) - param.hash, ' '), 0);
}

void ft_print_x(t_param param, char *str, t_buf *buf)
{
	int		tmp;

	tmp = ft_strlen(str);
	param.precision > -1 ? param.zero = 0 : 0;
	if (*str != '0')
	{
		param.hash == 1 ? param.hash = 2 : 0;
		if (param.minus == 0)
			minus_neg(param, str, tmp, buf);
		else
			minus_pos(param, str, tmp, buf);
	}
	else
	{
		tmp = 0;
		param.precision == -1 ? param.hash = 1 : 0;
		if (param.minus == 0)
			minus_neg_null(param, str, tmp, buf);
		else
			minus_pos_null(param, str, tmp, buf);
	}
}
