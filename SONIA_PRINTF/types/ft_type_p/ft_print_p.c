/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcummera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 01:45:15 by hcummera          #+#    #+#             */
/*   Updated: 2019/10/28 01:45:16 by hcummera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void		ft_type_p_zero(t_param param, int len, t_buf *buf)
{
	if (param.minus == 1)
	{
		ft_buf_add_s(buf, "0x", 1, 0);
		fill_with_zeros(&param, buf, len);
		p_precision_check(&param, buf, len);
	}
	else
	{
		p_precision_check(&param, buf, len);
		ft_buf_add_s(buf, "0x", 1, 0);
		fill_with_zeros(&param, buf, len);
	}
}

void		ft_type_p_minus(t_param param, char *str, int len, t_buf *buf)
{
	ft_buf_add_s(buf, "0x", 1, 0);
	fill_with_zeros(&param, buf, len);
	ft_buf_add_s(buf, str, 0, 0);
	p_precision_check(&param, buf, len);
}

void		ft_type_p_else(t_param param, char *str, int len, t_buf *buf)
{
	p_precision_check(&param, buf, len);
	ft_buf_add_s(buf, "0x", 1, 0);
	fill_with_zeros(&param, buf, len);
	ft_buf_add_s(buf, str, 0, 0);
}
