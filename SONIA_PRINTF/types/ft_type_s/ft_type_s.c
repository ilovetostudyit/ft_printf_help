#include "../../ft_printf.h"

void			ft_type_s(t_param param, char *ap, t_buf *buf) // разобраться в том, в каких случаях работают функции сверху
{
		//printf("%ap\n", "			Обрабатываем, флаг ap");
	int	tmp;
	
	tmp = ft_strlen(ap);
	if (param.precision > -1 && param.minus == 0)
		ft_type_s_minus(param, ap, tmp, buf);
	else if (param.precision > -1 && param.minus != 0)
		ft_type_s_prec_pos(param, ap, tmp, buf);
	else
		ft_type_s_prec_neg(param, ap, tmp, buf);
		//printf("%s\n", "			Обрабатываем, флаг s");
}
