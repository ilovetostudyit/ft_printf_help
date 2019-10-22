/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:31:33 by ehaggon           #+#    #+#             */
/*   Updated: 2019/10/22 16:30:35 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(char *str, ...)
{
	va_list		ap;
    size_t		res;
    t_buf       buf;
    t_param     param;

    va_start(ap, str);
    ft_printf_init(&buf, &param);
    if ((res = ft_get_res(&buf, &param, &str, &ap)) != -1)
        ft_print_res(&buf);
    ft_free_buf(&buf);
    va_end(ap);
    return((int)res);
}

size_t          ft_get_res(t_buf *buf, t_param *param, char **str, va_list *ap)
{
    printf("%s\n", "получаю результат");
    while (**str)
	{
		if (**str == '%')
			ft_percent_main(buf, param, str, ap);
		else if (**str == '{')
			ft_colour_main(str, buf);
		else
			ft_buf_add_c(buf, str);
		**str ? (*str)++ : NULL;
		if (buf->err == 1)
			return (-1);
	}
    return(buf->size);
}

void            ft_print_res(t_buf *buf)
{
    printf("%s\n","тут я печатаю результат");
    write(1, buf->buf, buf->top + 1);
}

void            ft_buf_add_c(t_buf *buf, char **str)
{
    printf("%s\n", "тут стоит заглушка, которая обрабатывает процент");
}
