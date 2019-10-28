/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils_o.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcummera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 01:44:38 by hcummera          #+#    #+#             */
/*   Updated: 2019/10/28 01:44:40 by hcummera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void		o_hash_check(t_param *p, t_buf *buf)
{
	if (p->hash == 1 && p->precision < 1)
		ft_print_else(buf, '0');
}

void		o_minus_check(t_param *p, t_buf *buf, int tmp)
{
	if (p->minus == 1 && p->width - p->hash > tmp)
		ft_buf_add_s(buf, ft_memnew(p->width - p->hash - tmp, ' '), 0, 0);
}

void		o_minus_zero(t_param *p, t_buf *buf, int tmp)
{
	if (p->minus == 0 && p->width - p->hash > tmp)
	{
		if (p->zero == 1)
			ft_buf_add_s(buf, ft_memnew(p->width - p->hash - tmp, '0'), 0, 0);
		else if (p->zero == 0)
			ft_buf_add_s(buf, ft_memnew(p->width - p->hash - tmp, ' '), 0, 0);
	}
}

void		o_prec_check(t_param p, t_buf *buf, int tmp)
{
	if (p.precision > 0 && (p.precision >= tmp))
		ft_buf_add_s(buf, ft_memnew(p.precision - tmp, '0'), 0, 0);
}
