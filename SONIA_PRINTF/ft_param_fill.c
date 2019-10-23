#include "ft_printf.h"

int				ft_param_fill(t_param *param, char **str, va_list *ap)
{
	printf("	Добавляем новый параметр\n");
	ft_flags(param, str);
	ft_get_width(param, str, ap);
	if (**str == '*' || (**str >= '0' && **str <= '9'))
		ft_get_width(param, str, ap);
	if (**str == '.')
	{
		if ((ft_get_prec(param, str, ap)) == -1)
			return (-1);
	}
	ft_get_length(param, str);
	if (**str && (**str == '0' || **str == '+' || **str == '-' ||
			**str == ' ' || **str == '#'))
		ft_flags(param, str);
	return (1);
}

int 	ft_flags(t_param *param, char **str)
{
	printf("	Ищу флаг\n");
	return(0);
}

int 	ft_get_width(t_param *param, char **str,va_list *ap)
{
	printf("	Ищу ширину\n");
	return(0);
}

int 	ft_get_length(t_param *param, char **str)
{
	printf("	Ищу длину\n");
	return(0);
}

int 	ft_get_prec(t_param *param, char **str,va_list *ap)
{
	printf("	Ищу точность\n");
	return(0);
}