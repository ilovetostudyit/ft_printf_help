/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcummera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 04:35:16 by hcummera          #+#    #+#             */
/*   Updated: 2019/10/28 04:35:17 by hcummera         ###   ########.fr       */
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
	if (!(buf->buf = ft_strnew(BUF_SIZE)))
		return ;
}

void	ft_param_init(t_param *param)
{
	param->precision = -1;
	param->width = 0;
	param->minus = 0;
	param->plus = 0;
	param->zero = 0;
	param->hash = 0;
	param->space = 0;
	param->length = 0;
}
