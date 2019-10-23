#include "../ft_printf.h"

int 	ft_get_flags(t_param *param, char **str)
{
	printf("	Ищу флаг\n");
	return(0);
}

void    ft_get_other_flags(t_param *param, char **str)
{
    if (**str && (**str == '0' || **str == '+' || **str == '-' ||
			**str == ' ' || **str == '#'))
		ft_get_flags(param, str);
}