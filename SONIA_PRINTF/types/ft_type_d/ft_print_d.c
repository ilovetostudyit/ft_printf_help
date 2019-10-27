#include "../../ft_printf.h"

static void	ft_type_d_minus_pos(char *str, t_param param, int tmp, t_buf *buf)
{
    //printf("%s\n", "ЧТО ТУТ ПРОИСХОДИТ?");
    
	int	tmp_buf;

	tmp_buf = tmp;
	*str == '-' ? tmp_buf = tmp - 1 : 0;
	ft_space_check(str, &param, buf);
	ft_plus_check(str, &param, buf);
	ft_tire_check(str, buf);
	if (param.precision > tmp_buf && param.zero == 0)
		ft_buf_add_s(buf, ft_memnew(param.precision - tmp_buf, '0'), 0, 1);
	ft_buf_add_s(buf, str, 0, 1);
	if (param.width > param.precision && param.width > tmp && param.zero == 1)
		ft_buf_add_s(buf, ft_memnew(param.width - param.space - param.plus -
				(param.precision > tmp_buf ? param.precision : tmp_buf), '0'), 0, 1);
	if (param.width > param.precision && param.width > tmp)
		ft_buf_add_s(buf, ft_memnew(param.width -
			(param.space == 1 || param.plus == 1 || (tmp != tmp_buf)) -
				(param.precision > tmp_buf ? param.precision : tmp_buf), ' '), 0, 1);
}

static void	ft_type_d_prec_neg(char *str, t_param param, int tmp, t_buf *buf)
{
    //printf("%s\n", "Точности нет");
	param.plus == 1 && *str != '-' ? tmp += 1 : 0;
	ft_space_check(str, &param, buf);
	if (param.minus == 0 && param.zero == 0 && param.width > tmp)
		ft_buf_add_s(buf, ft_memnew(param.width - tmp -
			(param.space == 1 && param.plus == 0 && *str != '-'), ' '), 0, 1);
	ft_plus_check(str, &param, buf);
	ft_tire_check(str, buf);
	if (param.minus == 0 && param.zero == 1 && param.width > tmp)
		ft_buf_add_s(buf, ft_memnew(param.width - tmp -
			(param.space == 1 && param.plus == 0 && *str != '-'), '0'), 0, 1);
	ft_buf_add_s(buf, str, 0, 1);
	if (param.minus == 1 && param.width > tmp)
		ft_buf_add_s(buf, ft_memnew(param.width - tmp - param.space, ' '), 0, 1); 
}

static void	ft_type_d_prec_pos(char *str, t_param param, int tmp, t_buf *buf)
{
    //printf("%s\n", "Точность есть");
	int		tmp_buf;
    
	tmp_buf = tmp;
    *str == '-' ? tmp_buf = tmp - 1 : 0;
	*str == '0' && param.precision == 0 ? tmp_buf -= 1 : 0;
	ft_space_check(str, &param, buf);
	if (param.width > param.precision && param.width > tmp)
		ft_buf_add_s(buf, ft_memnew(param.width - param.space -
		(param.plus || *str == '-') - (param.precision > tmp_buf ? param.precision
		: tmp_buf), ' '), 0, 1);
	ft_plus_check(str, &param, buf);
	ft_tire_check(str, buf);
	if (param.precision > tmp_buf)
		ft_buf_add_s(buf, ft_memnew(param.precision - tmp_buf, '0'), 0, 1);
	ft_zero_check(str, &param, buf);
}

void		ft_print_d(t_param param, char *str, t_buf *buf)
{
    size_t str_len;

    str_len = ft_strlen(str);
	//printf("%s\n", "Осознаем, что у нас с точностью");
	if (param.precision <= -1)
		ft_type_d_prec_neg(str, param, str_len, buf);
	else if (param.minus == 0)
		ft_type_d_prec_pos(str, param, str_len, buf);
	else if (param.minus == 1)
		ft_type_d_minus_pos(str, param, str_len, buf);
}