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
int             ft_get_res();
void            ft_buf_init(t_buf *buf);
char			*ft_strnew(size_t size);
void            *ft_memset(void *b, int c, size_t len);
void            ft_printf_init(t_buf *buf, t_param *param);
void            ft_param_init(t_param *param);
void			ft_free_buf(t_buf *buf);
void            ft_print_res(t_buf *buf);