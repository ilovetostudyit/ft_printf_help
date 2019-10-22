#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct		s_buf
{
	size_t			top;
	size_t			size;
	int				err;
	char			*buf;
}					t_buf;

typedef struct		s_param
{
	unsigned char	length;
	char			minus;
	char			plus;
	char			zero;
	char			hasht;
	char			space;
	int				width;
	int				precision;
}					t_param;

# define BUF_SIZE 1000
int				ft_printf(char *str, ...);
size_t          ft_get_res(t_buf *buf, t_param *param, char **str, va_list *ap);
void            ft_buf_init(t_buf *buf);
char			*ft_strnew(size_t size);
void            *ft_memset(void *b, int c, size_t len);
void            ft_printf_init(t_buf *buf, t_param *param);
void            ft_param_init(t_param *param);
void			ft_free_buf(t_buf *buf);
void            ft_print_res(t_buf *buf);
void            ft_percent_main(t_buf *buf, t_param *param, char **str, va_list *ap);
void            ft_colour_main(char **str, t_buf *buf);
void            ft_print_else(t_buf *buf, char str);
int				ft_add_new_param(t_param *param, char **str, va_list *ap);
void			ft_print_str(int top, char *str);
void			ft_null_str(char *str);

