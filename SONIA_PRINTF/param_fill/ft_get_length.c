#include "../ft_printf.h"

void 	ft_get_length(t_param *param, char **str)
{
	//printf("	Ищу длину\n");
    if (**str == 'L' || **str == 'l' || **str == 'h' ||
		    **str == 'j' || **str == 'z')
	{
		param->length += **str;
		*str += 1;
	}
	if ((param->length == 'l' && **str == 'l') ||
		(param->length == 'h' && **str == 'h'))
	{
		param->length += **str;
		*str += 1;
	}
}