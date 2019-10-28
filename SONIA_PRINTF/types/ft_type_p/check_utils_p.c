/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 01:45:08 by hcummera          #+#    #+#             */
/*   Updated: 2019/10/28 09:13:08 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	fill_with_zeros(t_param *param, t_buf *buf, int len)
{
	if (param->precision > len - 2)
		ft_buf_s(buf, ft_memnew(param->precision - len + 2, '0'), 0, 0);
}

void	p_precision_check(t_param *param, t_buf *buf, int len)
{
	if (param->w > param->precision && param->w > len)
	{
		if (param->precision > len - 2)
			ft_buf_s(buf,
					ft_memnew(param->w - param->precision - 2, ' '), 0, 0);
		else
			ft_buf_s(buf, ft_memnew(param->w - len, ' '), 0, 0);
	}
}
