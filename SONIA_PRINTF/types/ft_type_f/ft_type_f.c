/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 01:44:31 by hcummera          #+#    #+#             */
/*   Updated: 2019/10/28 09:25:18 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static void		minus_pos(t_param p, char *i, int tmp, t_buf *buf)
{
	if (p.spc == 1 && p.pl == 0 && (buf->fm == 0))
		ft_print_else(buf, ' ');
	p.pl == 1 && (buf->fm == 0) ? ft_print_else(buf, '+') : 0;
	(buf->fm == 1) ? ft_print_else(buf, '-') : 0;
	ft_buf_s(buf, i, 0, 1);
	p.hash == 1 && p.precision == 0 ? ft_print_else(buf, '.') : 0;
	if ((p.w - tmp - ((buf->fm == 0) && (p.pl == 1
		|| p.spc == 1))) > 0)
		ft_buf_s(buf, ft_memnew((p.w - tmp -
			((buf->fm == 0) && (p.pl == 1
				|| p.spc == 1))), ' '), 0, 1);
}

static void		ft_print_f(t_param p, char *i, t_buf *buf)
{
	int	tmp;

	tmp = ft_strlen(i);
	tmp = (*i == '-') ? tmp : tmp + buf->fm;
	if (p.precision == 0 && p.hash == 1)
		tmp += 1;
	if (p.minus == 0)
		minus_neg_f(p, i, tmp, buf);
	if (p.minus == 1)
		minus_pos(p, i, tmp, buf);
}

void			ft_type_f(t_param p, va_list ap, t_buf *buf)
{
	buf->fm = 0;
	p.precision == -1 ? p.precision = 6 : 0;
	p.precision == -2 ? p.precision = 0 : 0;
	if (p.length == 'L')
		ft_print_f(p,
				ft_float_f(va_arg(ap, long double), p.precision, buf), buf);
	else
		ft_print_f(p,
				ft_float_f(va_arg(ap, double), p.precision, buf), buf);
}
