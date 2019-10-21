/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:31:33 by ehaggon           #+#    #+#             */
/*   Updated: 2019/10/21 16:40:28 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(char *str, ...)
{
	va_list		ap;
    int			res;
    t_buf       buf;
    t_param     param;

    va_start(ap, str);
    ft_printf_init(&buf, &param);
    res = buf.size;
    ft_print_res(&buf);
    ft_free_buf(&buf);
    va_end(ap);
    return(res);
}

int             ft_get_res()
{
    printf("%s\n", "получаю результат");;
    return(0);
}

void            ft_print_res(t_buf *buf)
{
    printf("%s\n","тут я печатаю результат");
    write(1, buf->buf, buf->top + 1);
}