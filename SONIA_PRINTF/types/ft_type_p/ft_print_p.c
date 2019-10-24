#include "../../ft_printf.h"

void		ft_type_p_zero(t_param param, int len, t_buf *buf)
{
	if (param.minus == 1)
	{
		ft_buf_add_s(buf, "0x", 1);
		fill_with_zeros(&param, buf, len);
		if (param.width > param.precision && param.width > len &&
			param.precision > len - 2)
			ft_buf_add_s(buf,
						ft_memnew(param.width - param.precision - 2, ' '), 0);
		if (param.width > param.precision && param.width > len &&
			param.precision < len - 2)
			ft_buf_add_s(buf, ft_memnew(param.width - len, ' '), 0);
	}
	else
	{
		if (param.width > param.precision && param.width > len)
		{
			(param.precision > len - 2) ?
	ft_buf_add_s(buf, ft_memnew(param.width - param.precision - 2, ' '), 0) :
	ft_buf_add_s(buf, ft_memnew(param.width - len, ' '), 0);
		}
		ft_buf_add_s(buf, "0x", 1);
		if (param.precision > len - 2)
			ft_buf_add_s(buf, ft_memnew(param.precision - len + 2, '0'), 0);
	}
}

void		ft_type_p_minus(t_param param, char *str, int len, t_buf *buf)
{
	ft_buf_add_s(buf, "0x", 1);
	fill_with_zeros(&param, buf, len);
	ft_buf_add_s(buf, str, 0);
	if (param.width > param.precision && param.width > len)
	{
		if (param.precision > len - 2)
			ft_buf_add_s(buf,
					ft_memnew(param.width - param.precision - 2, ' '), 0);
		else
			ft_buf_add_s(buf, ft_memnew(param.width - len, ' '), 0);
	}
}

void		ft_type_p_else(t_param param, char *str, int len, t_buf *buf)
{
	if (param.width > param.precision && param.width > len)
	{
		if (param.precision > len - 2)
			ft_buf_add_s(buf,
					ft_memnew(param.width - param.precision - 2, ' '), 0);
		else
			ft_buf_add_s(buf, ft_memnew(param.width - len, ' '), 0);
	}
	ft_buf_add_s(buf, "0x", 1);
	if (param.precision > len - 2)
		ft_buf_add_s(buf, ft_memnew(param.precision - len + 2, '0'), 0);
	ft_buf_add_s(buf, str, 0);
}
