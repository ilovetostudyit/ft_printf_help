#include "../../ft_printf.h"

void		ft_type_p_zero(t_param list, int len, t_buf *buf)
{
	if (list.minus == 1)
	{
		ft_buf_add_s(buf, "0x", 1);
		if (list.precision > len - 2)
			ft_buf_add_s(buf, ft_memnew(list.precision - len + 2, '0'), 0);
		if (list.width > list.precision && list.width > len &&
			list.precision > len - 2)
			ft_buf_add_s(buf,
						ft_memnew(list.width - list.precision - 2, ' '), 0);
		if (list.width > list.precision && list.width > len &&
			list.precision < len - 2)
			ft_buf_add_s(buf, ft_memnew(list.width - len, ' '), 0);
	}
	else
	{
		if (list.width > list.precision && list.width > len)
		{
			(list.precision > len - 2) ?
	ft_buf_add_s(buf, ft_memnew(list.width - list.precision - 2, ' '), 0) :
	ft_buf_add_s(buf, ft_memnew(list.width - len, ' '), 0);
		}
		ft_buf_add_s(buf, "0x", 1);
		if (list.precision > len - 2)
			ft_buf_add_s(buf, ft_memnew(list.precision - len + 2, '0'), 0);
	}
}

void		ft_type_p_minus(t_param list, char *str, int len, t_buf *buf)
{
	ft_buf_add_s(buf, "0x", 1);
	if (list.precision > len - 2)
		ft_buf_add_s(buf, ft_memnew(list.precision - len + 2, '0'), 0);
	ft_buf_add_s(buf, str, 0);
	if (list.width > list.precision && list.width > len)
	{
		if (list.precision > len - 2)
			ft_buf_add_s(buf,
					ft_memnew(list.width - list.precision - 2, ' '), 0);
		else
			ft_buf_add_s(buf, ft_memnew(list.width - len, ' '), 0);
	}
}

void		ft_type_p_else(t_param list, char *str, int len, t_buf *buf)
{
	if (list.width > list.precision && list.width > len)
	{
		if (list.precision > len - 2)
			ft_buf_add_s(buf,
					ft_memnew(list.width - list.precision - 2, ' '), 0);
		else
			ft_buf_add_s(buf, ft_memnew(list.width - len, ' '), 0);
	}
	ft_buf_add_s(buf, "0x", 1);
	if (list.precision > len - 2)
		ft_buf_add_s(buf, ft_memnew(list.precision - len + 2, '0'), 0);
	ft_buf_add_s(buf, str, 0);
}
