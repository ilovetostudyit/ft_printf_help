#include "../../ft_printf.h"

static void	minus_neg(t_param param, char *i, int tmp, t_buf *buf)
{
	if ((param.width - (param.precision > tmp ? param.precision : tmp) -
											param.hash) >= 0 && param.zero != 1)
		ft_buf_add_s(buf, ft_memnew(param.width - (param.precision > tmp ?
		param.precision : tmp) - param.hash, ' '), 0, 0);
	if (param.hash != 0)
		ft_buf_add_s(buf, "0X", 1, 0);
	if ((param.width - (param.precision > tmp ? param.precision : tmp) -
											param.hash) >= 0 && param.zero == 1)
		ft_buf_add_s(buf, ft_memnew(param.width - tmp -
		param.hash, '0'), 0, 0);
	if (param.precision > tmp)
		ft_buf_add_s(buf, ft_memnew(param.precision - tmp, '0'), 0, 0);
	ft_buf_add_s(buf, i, 0, 0);
}

static void	minus_pos(t_param param, char *i, int tmp, t_buf *buf)
{
	if (param.hash != 0)
		ft_buf_add_s(buf, "0X", 1, 0);
	if (param.precision > tmp)
		ft_buf_add_s(buf, ft_memnew(param.precision - tmp, '0'), 0, 0);
	ft_buf_add_s(buf, i, 0, 0);
	if ((param.width - (param.precision > tmp ? param.precision : tmp) -
											param.hash) >= 0 && param.zero != 1)
		ft_buf_add_s(buf, ft_memnew(param.width - (param.precision > tmp ?
		param.precision : tmp) - param.hash, ' '), 0, 0);
}

static void	str_up(char *i)
{
	int	j;

	j = 0;
	while (i[j] != 0)
	{
		if (i[j] >= 'a' && i[j] <= 'z')
			i[j] = i[j] - 32;
		j++;
	}
}

void    ft_print_x_up(t_param param, char *str, t_buf *buf)
{
	int		tmp;

	str_up(str);
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