#include "../ft_printf.h"

int     ft_get_prec_main(t_param *param, char **str,va_list *ap)
{
    if (**str == '.')
		if ((ft_get_prec(param, str, ap)) == -1)
			return (-1);
    return(0);
}

int 	ft_get_prec(t_param *param, char **str,va_list *ap)
{
	printf("	Ищу точность\n");
	return(0);
}