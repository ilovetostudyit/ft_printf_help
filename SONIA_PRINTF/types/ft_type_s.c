#include "../ft_printf.h"

static char	*ft_memnew(size_t i, int lett) //если понадобится где-то ещё - убрать
{
	return (ft_memset(ft_strnew(i), lett, i));
}

static size_t	ft_strlen(const char *ap) //хмм, а мы будем либу подключать или как? 
{
	char *tmp;
	
	if (ap)
	{
		tmp = (char*)ap;
		if (ap)
			while (*tmp)
				tmp++;
		return (tmp - ap);
	}
	return (0);
}


static void		prec_pos(t_param param, char *ap, int tmp, t_buf *buf)
{
		if (ap != NULL)
			ft_buf_add_ns(buf, ap, tmp < param.precision ? tmp : param.precision, 1);
		else
			ft_buf_add_ns(buf, "(null)", param.precision, 1);
		if (param.width > (tmp < param.precision ? tmp : param.precision) && param.zero == 1)
			ft_buf_add_s(buf, ft_memnew(param.width - (tmp < param.precision ? tmp : param.precision) - (tmp == 0 ? param.precision : 0), '0'), 1);
		else if (param.width > (tmp < param.precision ? tmp : param.precision) && ap != NULL)
			ft_buf_add_s(buf, ft_memnew(param.width - (tmp < param.precision ? tmp : param.precision), ' '), 1);
}


static void		minus_neg(t_param param, char *ap, int tmp, t_buf *buf)
{
	if (param.width > (tmp < param.precision ? tmp : param.precision) && param.zero == 1)
		ft_buf_add_s(buf, ft_memnew(param.width - (tmp < param.precision ? tmp : param.precision) - (tmp == 0 ? param.precision : 0), '0'), 1);
	else if (param.width > (tmp < param.precision ? tmp : param.precision) && ap != NULL)
		ft_buf_add_s(buf, ft_memnew(param.width - (tmp < param.precision ? tmp : param.precision), ' '), 1);
	if (ap != NULL)
		ft_buf_add_ns(buf, ap, tmp < param.precision ? tmp : param.precision, 1);
	else
		ft_buf_add_ns(buf, "(null)", param.precision, 1);
}

static void		prec_neg(t_param param, char *ap, int tmp, t_buf *buf)
{
	if (param.minus == 0)
	{
		if (param.width > tmp && param.zero == 0 && ap != NULL)
			ft_buf_add_s(buf, ft_memnew(param.width - tmp, ' '), 1);
		else if (param.width > tmp && param.zero == 1)
			ft_buf_add_s(buf, ft_memnew(param.width - tmp, '0'), 1);
		if (ap != NULL)
			ft_buf_add_s(buf, ap, 1);
		else
			ft_buf_add_s(buf, "(null)", 1);
	}
	else
	{
		if (ap != NULL)
			ft_buf_add_s(buf, ap, 1);
		else
			ft_buf_add_s(buf, "(null)", 1);
		if (param.width > tmp && param.zero == 0 && ap != NULL)
			ft_buf_add_s(buf, ft_memnew(param.width - tmp, ' '), 1);
		else if (param.width > tmp && param.zero == 1)
			ft_buf_add_s(buf, ft_memnew(param.width - tmp, '0'), 1);
	}
}

void			ft_type_s(t_param param, char *ap, t_buf *buf) // разобраться в том, в каких случаях работают функции сверху
{
		//printf("%ap\n", "			Обрабатываем, флаг ap");
	int	tmp;
	
	tmp = ft_strlen(ap);
	if (param.precision > -1 && param.minus == 0)
		minus_neg(param, ap, tmp, buf);
	else if (param.precision > -1 && param.minus != 0)
		prec_pos(param, ap, tmp, buf);
	else
		prec_neg(param, ap, tmp, buf);
		//printf("%s\n", "			Обрабатываем, флаг s");
}
