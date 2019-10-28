/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_utils_other.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 09:22:11 by ehaggon           #+#    #+#             */
/*   Updated: 2019/10/28 09:33:02 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static void	just_print(t_param p, char *i, t_buf *buf, int tmp)
{
	if ((p.w - tmp - ((buf->fm == 0) && (p.pl == 1))) > 0)
		ft_buf_s(buf, ft_memnew((p.w - tmp - ((buf->fm == 0)
				&& (p.pl == 1))), ' '), 0, 1);
	p.pl == 1 && (buf->fm == 0) ? ft_print_else(buf, '+') : 0;
	(buf->fm == 1) ? ft_print_else(buf, '-') : 0;
	ft_buf_s(buf, i, 0, 1);
	p.hash == 1 && p.precision == 0 ? ft_print_else(buf, '.') : 0;
}

static void	minus_zero_f(t_param p, char *i, int tmp, t_buf *buf)
{
	ft_buf_s(buf, ft_memnew(p.w - tmp - ((buf->fm == 0) &&
			((p.pl == 1 || p.spc == 1))), ' '), 0, 1);
	((p.spc == 1 && (buf->fm == 0)) || (p.spc == 1
			&& p.pl == 0)) ? ft_print_else(buf, ' ') : 0;
	p.pl == 1 && (buf->fm == 0) ? ft_print_else(buf, '+') : 0;
	(buf->fm == 1) ? ft_print_else(buf, '-') : 0;
}

void		minus_neg_f(t_param p, char *i, int tmp, t_buf *buf)
{
	if (p.w > (tmp + ((buf->fm == 0) && (p.pl == 1 || p.spc == 1))))
	{
		if (p.zero == 0)
		{
			minus_zero_f(p, i, tmp, buf);
		}
		else
		{
			((p.spc == 1 && (buf->fm == 0)) || (p.spc == 1
						&& p.pl == 0)) ? ft_print_else(buf, ' ') : 0;
			p.pl == 1 && (buf->fm == 0) ? ft_print_else(buf, '+') : 0;
			(buf->fm == 1) ? ft_print_else(buf, '-') : 0;
			if ((p.w - tmp - ((buf->fm == 0) && (p.pl == 1 || p.spc == 1))) > 0)
				ft_buf_s(buf, ft_memnew((p.w - tmp - ((buf->fm == 0)
				&& (p.pl == 1 || p.spc == 1))), '0'), 0, 1);
		}
		ft_buf_s(buf, i, 1, 1);
		p.hash == 1 && p.precision == 0 ? ft_print_else(buf, '.') : 0;
	}
	else
		just_print(p, i, buf, tmp);
}
