/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o_zero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcummera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 01:44:45 by hcummera          #+#    #+#             */
/*   Updated: 2019/10/28 01:44:46 by hcummera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void			prec_neg_null(char *str, t_param param, t_buf *buf)
{
	int tmp;

	tmp = 0;
	param.hash == 0 ? tmp = 1 : 0;
	o_minus_zero(&param, buf, tmp);
	param.hash == 1 ? ft_print_else(buf, '0') : 0;
	param.hash != 1 ? ft_buf_add_s(buf, str, 0, 0) : 0;
	o_minus_check(&param, buf, tmp);
}

void			prec_pos_null(char *str, t_param param, t_buf *buf)
{
	if (param.minus == 0)
	{
		param.precision > -1 ? param.zero = 0 : 0;
		if (param.width > param.precision)
		{
			if (param.zero == 1)
				ft_buf_add_s(buf, ft_memnew(param.width - param.hash -
											param.precision, '0'), 0, 0);
			else if (param.zero == 0)
				ft_buf_add_s(buf, ft_memnew(param.width - (param.hash == 1 &&
							param.precision < 1) - param.precision, ' '), 0, 0);
		}
		o_hash_check(&param, buf);
		o_prec_check(param, buf, 0);
	}
	else
	{
		o_hash_check(&param, buf);
		o_prec_check(param, buf, 0);
		if (param.width > param.precision && param.zero == 0)
			ft_buf_add_s(buf, ft_memnew(param.width - (param.hash == 1 &&
							param.precision < 1) - param.precision, ' '), 0, 0);
	}
}
