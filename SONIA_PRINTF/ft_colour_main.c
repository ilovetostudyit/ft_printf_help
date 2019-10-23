#include "ft_printf.h"
char	*ft_detect_col(char *str, t_buf *buf)
{
	//printf("%s\n", "Определяем цвет");
	return (str);
}
void    ft_colour_main(char **str, t_buf *buf)
{
	//printf("%s\n", "Обрабатываем фигурные скобки");
	*str = ft_detect_col(*str, buf);
	//что это?
	**str != '}' ? ft_print_else(buf, **str) : NULL;
}
