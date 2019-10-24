#include "../../ft_printf.h"

void	*ft_memset_char(char *str, t_param param, char c)
{
	return(ft_memset(str, c, param.width - 1));
}

void	ft_type_c(t_param param, char c, t_buf *buf)
{
	char *str;
	
	str = ft_strnew(param.width - 1);
	////printf("%s\n", "		Обрабатываем, флаг c");
	if (param.minus == 0 && param.zero == 1 && param.width > 1)
		ft_buf_add_s(buf,ft_memset_char(str, param, '0'), 0);
	else if (param.minus == 0 && param.zero == 0 && param.width > 1)
		ft_buf_add_s(buf, ft_memset_char(str, param, ' '), 0);
	ft_print_else(buf, c);
	if (param.minus == 1 && param.width > 1)
		ft_buf_add_s(buf, ft_memset_char(str, param, ' '), 0);	
}

