#include "ft_printf.h"

static void		ft_type_small_alpha(va_list *ap, char **str, t_param *param, t_buf *buf)
{
	ft_printf("Обрабатываем если маленькая буква");
}
static void		ft_type_big_alpha(va_list *ap, char **str, t_param *param, t_buf *buf)
{
	ft_printf("Обрабатываем если заглавная буква");
}
static void		ft_type_symbol(va_list *ap, char **str, t_param *param, t_buf *buf)
{
	ft_printf("Обрабатываем если символ %");
}
static void		ft_type(va_list *ap, char **str, t_param *param, t_buf *buf)
{
	ft_printf("Определяем большая или маленькая буква или процент");
}

void ft_percent_main(t_buf *buf, t_param *param, char **str, va_list *ap)
{
	*str = *str + 1;
	ft_add_new_param(param, str, ap);
	ft_type(ap, str, param, buf);
    ft_printf("Обрабатываем проценты");
}
