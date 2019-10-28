/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 04:04:54 by hcummera          #+#    #+#             */
/*   Updated: 2019/10/28 09:18:30 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static void	minus_pos(char *i, t_param param, int tmp, t_buf *buf)
{
	u_prec_tmp_check(param, buf, tmp);
	ft_buf_s(buf, i, 0, 1);
	if (param.w > param.precision && param.w > tmp)
	{
		if (param.zero == 1)
			ft_buf_s(buf, ft_memnew(param.w - param.spc -
				(param.precision > tmp ? param.precision : tmp), '0'), 0, 1);
		ft_buf_s(buf, ft_memnew(param.w - param.spc -
			(param.precision > tmp ? param.precision : tmp), ' '), 0, 1);
	}
}

static void	prec_neg(char *i, t_param param, int tmp, t_buf *buf)
{
	if (param.minus == 0 && param.w > tmp)
	{
		if (param.zero == 0)
			ft_buf_s(buf, ft_memnew(param.w - tmp, ' '), 0, 1);
		else if (param.zero == 1)
			ft_buf_s(buf, ft_memnew(param.w - tmp, '0'), 0, 1);
	}
	ft_buf_s(buf, i, 0, 1);
	if (param.minus == 1 && param.w > tmp)
		ft_buf_s(buf, ft_memnew(param.w - tmp, ' '), 0, 1);
}

static void	prec_pos(char *i, t_param param, int tmp, t_buf *buf)
{
	*i == '0' && param.precision == 0 ? tmp -= 1 : 0;
	if (param.w > param.precision && param.w > tmp)
	{
		ft_buf_s(buf, ft_memnew(param.w - param.spc -
			(param.precision > tmp ? param.precision : tmp), ' '), 0, 1);
		if (param.zero == 1)
			ft_buf_s(buf, ft_memnew(param.w - param.spc -
			(param.precision > tmp ? param.precision : tmp), '0'), 0, 1);
	}
	u_prec_tmp_check(param, buf, tmp);
	*i == '0' && param.precision == 0 ? NULL : ft_buf_s(buf, i, 0, 1);
}

void		ft_print_u(t_param param, char *ap, t_buf *buf)
{
	param.precision > -1 ? param.zero = 0 : 0;
	if (param.precision == -1)
		prec_neg(ap, param, ft_strlen(ap), buf);
	else if (param.minus == 0)
		prec_pos(ap, param, ft_strlen(ap), buf);
	else if (param.minus == 1)
		minus_pos(ap, param, ft_strlen(ap), buf);
}
