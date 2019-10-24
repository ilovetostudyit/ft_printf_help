/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:31:33 by ehaggon           #+#    #+#             */
/*   Updated: 2019/10/24 16:17:52 by ehaggon          ###   ########.fr       */
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
    //printf("%s\n", "получаю результат");
    while (**str)
	{
		if (**str == '%')
			ft_percent_main(buf, param, str, ap);
		/*else if (**str == '{')
			ft_colour_main(str, buf);*/
		else
			ft_print_else(buf, **str);
		**str ? (*str)++ : NULL;
		if (buf->err == 1)
			return (-1);
	}
    return(buf->size);
}
