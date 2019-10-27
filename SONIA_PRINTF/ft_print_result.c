#include "ft_printf.h"

void				ft_buf_add_ns(t_buf *buf, char *str, size_t n, int flag)
{
	//printf("%s\n","тут я печатаю результат, но как-то иначе 0_о (NS)");
	int		putch;
	char	*beg;

	if (buf->top + 1 + n >= BUF_SIZE)
	{
		buf->size += buf->top + 1;
		ft_print_res(buf);
		ft_null_str_buf(buf->buf);
		buf->top = -1;
	}
	flag == 0 ? beg = str : 0;
	if (n >= BUF_SIZE)
	{
		buf->size += n;
		write(1, str, n);
	}
	else
		while (*str && n--)
		{
			putch = ft_putchar(*str, buf->buf + 1 + buf->top);
			buf->size += putch;
			buf->top += putch;
			str++;
		}
	flag == 0 ? free(beg) : 0;
}

void				ft_buf_add_s(t_buf *buf, char *str, int flag, int d)
{
	//printf("%s\n","тут я печатаю результат, но как-то иначе 0_о(S)");
	int		putch;
	size_t	len;
	char	*beg;

	len = ft_strlen(str);
	flag == 0 ? beg = str : 0;
	if (d == 1)
		*str == '-' ? str++ : 0;
	if (buf->top + 1 + len >= BUF_SIZE)
	{
		ft_print_res(buf);
		ft_null_str_buf(buf->buf);
	}
	buf->top + 1 + len >= BUF_SIZE ? buf->top = -1 : 0;
	if (len >= BUF_SIZE)
	{
		buf->size += len;
		write(1, str, len);
	}
	else
		while (*str)
		{
			putch = ft_putchar(*str, buf->buf + 1 + buf->top);
			buf->size += putch;
			buf->top += putch;
			str++;
		}
	flag == 0 ? free(beg) : 0;	
}

void            ft_print_res(t_buf *buf)
{
    ////printf("%s\n","тут я печатаю результат");
    write(1, buf->buf, buf->top + 1);
}

void            ft_print_else(t_buf *buf, char str)
{
    ////printf("%s\n", "обрабатываю остальные символы");
	if (buf->top + 1 >= BUF_SIZE)
	{
		ft_print_res(buf);
        ft_null_str_buf(buf->buf);
		buf->top = -1;
	}
	buf->buf[++buf->top] = str;
	buf->size++;
}
