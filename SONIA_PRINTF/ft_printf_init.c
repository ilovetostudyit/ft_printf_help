#include "ft_printf.h"

void ft_printf_init(t_buf *buf, t_param *param)
{
    //printf("%s\n", "инициализация структур:");
    ft_buf_init(buf);
    ft_param_init(param);
    //printf("%s\n", "инициализация закончена!");
}

void ft_buf_init(t_buf *buf)
{
    buf->err = 0;
    buf->size = 0;
	buf->top = -1;
	if (!(buf->buf = ft_strnew(BUF_SIZE)))
		return ;
    //printf("%s\n", "- инциализировал буфер");
}

void ft_param_init(t_param *param)
{
    param->precision = -1;
	param->width = 0;
	param->minus = 0;
	param->plus = 0;
	param->zero = 0;
	param->hash = 0;
	param->space = 0;
	param->length = 0;
    //printf("%s\n", "- инциализировал параметры");
}