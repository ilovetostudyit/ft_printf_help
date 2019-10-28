/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 01:43:03 by hcummera          #+#    #+#             */
/*   Updated: 2019/10/28 09:13:08 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static void		ft_type_d_minus_pos(char *s, t_param p, int tmp, t_buf *b)
{
	int	tmp_b;

	tmp_b = tmp;
	*s == '-' ? tmp_b = tmp - 1 : 0;
	ft_space_check(s, &p, b);
	ft_plus_check(s, &p, b);
	ft_tire_check(s, b);
	if (p.precision > tmp_b && p.zero == 0)
		ft_buf_s(b, ft_memnew(p.precision - tmp_b, '0'), 0, 1);
	ft_buf_s(b, s, 0, 1);
	if (p.w > p.precision && p.w > tmp && p.zero == 1)
		ft_buf_s(b, ft_memnew(p.w - p.spc - p.pl -
				(p.precision > tmp_b ? p.precision : tmp_b),
				'0'), 0, 1);
	if (p.w > p.precision && p.w > tmp)
		ft_buf_s(b, ft_memnew(p.w - (p.spc == 1 || p.pl == 1 ||
									(tmp != tmp_b)) - (p.precision > tmp_b ?
										p.precision : tmp_b), ' '), 0, 1);
}

static void		ft_type_d_prec_neg(char *s, t_param p, int tmp, t_buf *b)
{
	p.pl == 1 && *s != '-' ? tmp += 1 : 0;
	ft_space_check(s, &p, b);
	if (p.minus == 0 && p.zero == 0 && p.w > tmp)
		ft_buf_s(b, ft_memnew(p.w - tmp -
			(p.spc == 1 && p.pl == 0 && *s != '-'), ' '), 0, 1);
	ft_plus_check(s, &p, b);
	ft_tire_check(s, b);
	if (p.minus == 0 && p.zero == 1 && p.w > tmp)
		ft_buf_s(b, ft_memnew(p.w - tmp -
			(p.spc == 1 && p.pl == 0 && *s != '-'), '0'), 0, 1);
	ft_buf_s(b, s, 0, 1);
	if (p.minus == 1 && p.w > tmp)
		ft_buf_s(b, ft_memnew(p.w - tmp - p.spc, ' '), 0, 1);
}

static void		ft_type_d_prec_pos(char *s, t_param p, int tmp, t_buf *b)
{
	int		tmp_b;

	tmp_b = tmp;
	*s == '-' ? tmp_b = tmp - 1 : 0;
	*s == '0' && p.precision == 0 ? tmp_b -= 1 : 0;
	ft_space_check(s, &p, b);
	if (p.w > p.precision && p.w > tmp)
		ft_buf_s(b, ft_memnew(p.w - p.spc -
		(p.pl || *s == '-') - (p.precision > tmp_b ? p.precision
		: tmp_b), ' '), 0, 1);
	ft_plus_check(s, &p, b);
	ft_tire_check(s, b);
	if (p.precision > tmp_b)
		ft_buf_s(b, ft_memnew(p.precision - tmp_b, '0'), 0, 1);
	ft_zero_check(s, &p, b);
}

void			ft_print_d(t_param p, char *s, t_buf *b)
{
	size_t s_len;

	s_len = ft_strlen(s);
	if (p.precision <= -1)
		ft_type_d_prec_neg(s, p, s_len, b);
	else if (p.minus == 0)
		ft_type_d_prec_pos(s, p, s_len, b);
	else if (p.minus == 1)
		ft_type_d_minus_pos(s, p, s_len, b);
}
