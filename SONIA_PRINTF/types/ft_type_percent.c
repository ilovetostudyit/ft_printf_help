/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcummera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 01:45:35 by hcummera          #+#    #+#             */
/*   Updated: 2019/10/28 01:45:36 by hcummera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_type_percent(t_param param, t_buf *buf)
{
	if (param.minus == 0 && param.zero == 1 && param.width > 1)
		ft_buf_add_s(buf,
			ft_memset(ft_strnew(param.width - 1), '0', param.width - 1), 0, 0);
	else if (param.width > 1 && param.minus == 0)
		ft_buf_add_s(buf,
			ft_memset(ft_strnew(param.width - 1), ' ', param.width - 1), 0, 0);
	ft_print_else(buf, '%');
	if (param.width > 1 && param.minus == 1)
		ft_buf_add_s(buf,
			ft_memset(ft_strnew(param.width - 1), ' ', param.width - 1), 0, 0);
}
