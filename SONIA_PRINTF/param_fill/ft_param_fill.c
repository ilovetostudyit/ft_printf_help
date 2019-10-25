#include "../ft_printf.h"

int				ft_param_fill(t_param *param, char **str, va_list *ap)
{
	////printf("	Добавляем новый параметр\n");
	ft_get_flags(param, str);
	ft_get_width_main(param, str, ap);
	if (ft_get_prec_main(param, str, ap))
		return(-1);
	ft_get_length(param, str);
	ft_get_other_flags(param, str);
	return (1);
}
