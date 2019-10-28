/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 04:35:16 by hcummera          #+#    #+#             */
/*   Updated: 2019/10/28 09:11:41 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_init(t_buf *buf, t_param *param)
{
	ft_buf_init(buf);
	ft_param_init(param);
}

void	ft_buf_init(t_buf *buf)
{
	buf->err = 0;
	buf->size = 0;
	buf->top = -1;
	buf->fm = 0;
	if (!(buf->buf = ft_strnew(BUF_SIZE)))
		return ;
}

void	ft_param_init(t_param *param)
{
	param->precision = -1;
	param->w = 0;
	param->minus = 0;
	param->pl = 0;
	param->zero = 0;
	param->hash = 0;
	param->spc = 0;
	param->length = 0;
}
