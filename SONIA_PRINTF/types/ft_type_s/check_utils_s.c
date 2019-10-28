/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 01:45:42 by hcummera          #+#    #+#             */
/*   Updated: 2019/10/28 09:13:08 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void		s_ap_check(t_buf *buf, char *ap)
{
	if (ap != NULL)
		ft_buf_s(buf, ap, 1, 0);
	else
		ft_buf_s(buf, "(null)", 1, 0);
}

void		s_pres_ap_check(t_param p, char *ap, int tmp, t_buf *buf)
{
	if (ap != NULL)
		ft_buf_add_ns(buf, ap, tmp < p.precision ? tmp : p.precision, 1);
	else
		ft_buf_add_ns(buf, "(null)", p.precision, 1);
}

void		s_width_check(t_param p, char *ap, int tmp, t_buf *buf)
{
	if (p.w > tmp && p.zero == 0 && ap != NULL)
		ft_buf_s(buf, ft_memnew(p.w - tmp, ' '), 1, 0);
	else if (p.w > tmp && p.zero == 1)
		ft_buf_s(buf, ft_memnew(p.w - tmp, '0'), 1, 0);
}

void		s_pres_width_check(t_param p, char *ap, int tmp, t_buf *buf)
{
	if (p.w > (tmp < p.precision ? tmp : p.precision) && p.zero == 1)
		ft_buf_s(buf, ft_memnew(p.w - (tmp < p.precision ? tmp :
					p.precision) - (tmp == 0 ? p.precision : 0), '0'), 1, 0);
	else if (p.w > (tmp < p.precision ? tmp : p.precision) && ap != NULL)
		ft_buf_s(buf, ft_memnew(p.w - (tmp < p.precision ? tmp :
						p.precision), ' '), 1, 0);
}
