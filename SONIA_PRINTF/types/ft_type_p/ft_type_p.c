#include "../../ft_printf.h"

void			ft_type_p(t_param param, void *ptr, t_buf *buf)
{
	////printf("%s\n", "		Обрабатываем, флаг p");
	long long		tmp;
	char			*str;
	int				len;

	tmp = (unsigned long long)ptr;
	str = ft_itoa_base_ll(tmp, 16);
	len = ft_strlen(str) + 2;
	if (*str == '0' && len == 3 && param.precision > -1)
		ft_type_p_zero(param, len - 1, buf);
	else if (param.minus == 1)
		ft_type_p_minus(param, str, len, buf);
	else
		ft_type_p_else(param, str, len, buf);
}
