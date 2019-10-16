#include "ft_printf.h"
int				ft_printf(char *str, ...)
{
	va_list		ap;
    int			res;
    t_buf       buf;
    t_param     param;

    va_start(ap, str);
    ft_printf_init(&buf, &param);
    res = ft_get_res();
    va_end(ap);
    return(res);
}

int             ft_get_res()
{
    printf("%s\n", "получаю результат");;
    return(0);
}