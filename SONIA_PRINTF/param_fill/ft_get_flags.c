#include "../ft_printf.h"

//i can make it better
void	ft_get_flags(t_param *param, char **str)
{
	//printf("	Ищу флаг\n");
    while (**str && (**str == '0' || **str == '+' || **str == '-' ||
			**str == ' ' || **str == '#'))
	{
		(**str == '#') ? param->hash = 1 : 0;
		(**str == '-') ? param->minus = 1 : 0;
		(**str == '+') ? param->plus = 1 : 0;
		(**str == ' ') ? param->space = 1 : 0;
        (**str == '0') ? param->zero = 1 : 0;
		*str += 1;
	}
	(param->space == 1 && param->plus == 1) ? param->space = 0 : 1;
	(param->zero == 1 && param->minus == 1) ? param->zero = 0 : 1;
}

void    ft_get_other_flags(t_param *param, char **str)
{
    if (**str && (**str == '0' || **str == '+' || **str == '-' ||
			**str == ' ' || **str == '#'))
		ft_get_flags(param, str);
}