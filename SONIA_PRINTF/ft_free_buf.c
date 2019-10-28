/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_buf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:37:01 by ehaggon           #+#    #+#             */
/*   Updated: 2019/10/24 14:27:02 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_free_buf(t_buf *buf)
{
	free(buf->buf);
	buf = NULL;
}

void	ft_null_str_buf(char *str)
{
	while (*str)
	{
		*str = 0;
		str++;
	}
}
