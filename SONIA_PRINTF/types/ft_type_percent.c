/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 01:45:35 by hcummera          #+#    #+#             */
/*   Updated: 2019/10/28 09:13:08 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_type_percent(t_param param, t_buf *buf)
{
	if (param.minus == 0 && param.zero == 1 && param.w > 1)
		ft_buf_s(buf,
			ft_memset(ft_strnew(param.w - 1), '0', param.w - 1), 0, 0);
	else if (param.w > 1 && param.minus == 0)
		ft_buf_s(buf,
			ft_memset(ft_strnew(param.w - 1), ' ', param.w - 1), 0, 0);
	ft_print_else(buf, '%');
	if (param.w > 1 && param.minus == 1)
		ft_buf_s(buf,
			ft_memset(ft_strnew(param.w - 1), ' ', param.w - 1), 0, 0);
}
