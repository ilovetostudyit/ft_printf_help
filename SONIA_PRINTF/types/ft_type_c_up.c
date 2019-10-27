#include "../ft_printf.h"

static int			ft_len(wchar_t c)
{
	unsigned long long	cc;
	int					len;
	
	cc = (unsigned long long)c;
	len = 1 + (cc >= 127) + (cc >= 2047) + (cc >= 65535);
	return (len);
}

void			ft_type_c_up(t_param param, wchar_t c, t_buf *buf) //надо бы потестить
{
			////printf("%s\n", "		Обрабатываем, флаг C");
	int	len;
	int paramlen;
	char *str;

	if (c < 0)
		buf->err = 1;
	else
	{
		len = ft_len(c);
		paramlen = param.width - len;
			str = ft_strnew(param.width - len);
		if (param.minus == 0 && param.zero == 1 && paramlen > 0) // вот здесь убрала условие, осторожно!
			ft_buf_add_s(buf, ft_memset(str, '0', paramlen), 0, 0);
		else if (param.minus == 0 && param.zero == 0 && param.width > 1 && paramlen >= 0)
			ft_buf_add_s(buf, ft_memset(str, ' ', paramlen), 0, 0);
		if ((MB_CUR_MAX == 4 && c < 114112) || (MB_CUR_MAX == 3 && c < 65536) || (MB_CUR_MAX == 2 && c < 2048) || (MB_CUR_MAX == 1 && c < 127))
			ft_buf_add_nc(buf, c);
		else
			ft_print_else(buf, c);
		if (param.minus == 1 && param.width > len)
			ft_buf_add_s(buf, ft_memset(str, ' ', paramlen), 0, 0);
	}
}
