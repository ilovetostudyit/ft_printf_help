#include "ft_printf.h"

void            ft_print_res(t_buf *buf)
{
    printf("%s\n","тут я печатаю результат");
    write(1, buf->buf, buf->top + 1);
}

void			ft_print_str(int top, char *str)
{
	write(1, str, top + 1);
}

void            ft_print_else(t_buf *buf, char str)
{
    printf("%s\n", "обрабатываю остальные символы");
	if (buf->top + 1 >= BUF_SIZE)
	{
		ft_print_str(buf->top, buf->buf);
        ft_null_str(buf->buf);
		buf->top = -1;
	}
	buf->buf[++buf->top] = str;
	buf->size++;
}