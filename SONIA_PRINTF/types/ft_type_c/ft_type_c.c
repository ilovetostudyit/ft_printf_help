/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 01:42:16 by hcummera          #+#    #+#             */
/*   Updated: 2019/10/28 09:13:08 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	*ft_memset_char(char *str, t_param param, char c)
{
	return (ft_memset(str, c, param.w - 1));
}

void	ft_type_c(t_param param, char c, t_buf *buf)
{
	char *str;

	str = ft_strnew(param.w - 1);
	if (param.minus == 0 && param.zero == 1 && param.w > 1)
		ft_buf_s(buf, ft_memset_char(str, param, '0'), 0, 0);
	else if (param.minus == 0 && param.zero == 0 && param.w > 1)
		ft_buf_s(buf, ft_memset_char(str, param, ' '), 0, 0);
	ft_print_else(buf, c);
	if (param.minus == 1 && param.w > 1)
		ft_buf_s(buf, ft_memset_char(str, param, ' '), 0, 0);
}
