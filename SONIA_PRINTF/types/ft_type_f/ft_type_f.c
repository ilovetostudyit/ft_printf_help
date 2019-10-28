/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcummera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 01:44:31 by hcummera          #+#    #+#             */
/*   Updated: 2019/10/28 01:44:32 by hcummera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static void		just_print(t_param p, char *i, t_buf *buf)
{
	p.plus == 1 && *i != '-' ? ft_print_else(buf, '+') : 0;
	*i == '-' ? ft_print_else(buf, '-') : 0;
	ft_buf_add_s(buf, i, 0, 1);
	p.hash == 1 && p.precision == 0 ? ft_print_else(buf, '.') : 0;
}

static void		minus_pos(t_param p, char *i, int tmp, t_buf *buf)
{
	if (p.space == 1 && p.plus == 0 && *i != '-')
		ft_print_else(buf, ' ');
	p.plus == 1 && *i != '-' ? ft_print_else(buf, '+') : 0;
	ft_buf_add_s(buf, i, 0, 1);
	p.hash == 1 && p.precision == 0 ? ft_print_else(buf, '.') : 0;
	if (p.width > tmp + (*i != '-' && (p.plus == 1 || p.space == 1)))
		ft_buf_add_s(buf, ft_memnew(p.width - tmp - (*i != '-' &&
			(p.plus == 1 || p.space == 1)), ' '), 0, 1);
}

static void		minus_neg(t_param p, char *i, int tmp, t_buf *buf)
{
	if (p.width > tmp + (*i != '-' && (p.plus == 1 || p.space == 1)))
	{
		if (p.zero == 0)
		{
			ft_buf_add_s(buf, ft_memnew(p.width - tmp - (*i != '-' &&
				(p.plus == 1 || p.space == 1)), ' '), 0, 1);
			((p.space == 1 && *i != '-') || (p.space == 1
						&& p.plus == 0)) ? ft_print_else(buf, ' ') : 0;
			p.plus == 1 && *i != '-' ? ft_print_else(buf, '+') : 0;
		}
		else
		{
			((p.space == 1 && *i != '-') || (p.space == 1 &&
			p.plus == 0)) ? ft_print_else(buf, ' ') : 0;
			p.plus == 1 && *i != '-' ? ft_print_else(buf, '+') : 0;
			*i == '-' ? ft_print_else(buf, '-') : 0;
			*i == '-' ? i++ : 0;
			ft_buf_add_s(buf, ft_memnew(p.width - tmp -
				(p.plus || *i == '-') - p.space, '0'), 0, 1);
		}
		ft_buf_add_s(buf, i, 1, 1);
		p.hash == 1 && p.precision == 0 ? ft_print_else(buf, '.') : 0;
	}
	else
		just_print(p, i, buf);
}

static void		ft_print_f(t_param p, char *i, t_buf *buf)
{
	int	tmp;

	tmp = ft_strlen(i);
	if (p.precision == 0 && p.hash == 1)
		tmp += 1;
	if (p.minus == 0)
		minus_neg(p, i, tmp, buf);
	if (p.minus == 1)
		minus_pos(p, i, tmp, buf);
}

void			ft_type_f(t_param p, va_list ap, t_buf *buf)
{
	p.precision == -1 ? p.precision = 6 : 0;
	p.precision == -2 ? p.precision = 0 : 0;
	if (p.length == 'L')
		ft_print_f(p,
				ft_float_f(va_arg(ap, long double), p.precision), buf);
	else
		ft_print_f(p,
				ft_float_f(va_arg(ap, double), p.precision), buf);
}
