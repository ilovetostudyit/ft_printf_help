#include "../ft_printf.h"

void    ft_get_width_main(t_param *param, char **str, va_list *ap)
{
    ft_get_width(param, str, ap);
	if (**str == '*' || (**str >= '0' && **str <= '9'))
		ft_get_width(param, str, ap);
}

int 	ft_get_width(t_param *param, char **str,va_list *ap)
{
	printf("	Ищу ширину\n");
	return(0);
}
