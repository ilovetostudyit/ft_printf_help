#include "ft_printf.h"

void				ft_buf_add_s(t_buf *new, char *str, int flag)
{
	//printf("%s\n","тут я печатаю результат, но как-то иначе 0_о");
}

void            ft_print_res(t_buf *buf)
{
    //printf("%s\n","тут я печатаю результат");
    write(1, buf->buf, buf->top + 1);
}

void            ft_print_else(t_buf *buf, char str)
{
    //printf("%s\n", "обрабатываю остальные символы");
	if (buf->top + 1 >= BUF_SIZE)
	{
		ft_print_res(buf);
        ft_null_str_buf(buf->buf);
		buf->top = -1;
	}
	buf->buf[++buf->top] = str;
	buf->size++;
}
