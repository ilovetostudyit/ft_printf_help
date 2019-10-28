/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcummera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 01:43:18 by hcummera          #+#    #+#             */
/*   Updated: 2019/10/28 01:54:15 by hcummera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static int		ft_type_d_l_ll_check(t_param param, va_list ap, t_buf *buf)
{
	if (param.length == 0)
		ft_print_d(param, ft_itoa_base((int)va_arg(ap, int), 10), buf);
	else if (param.length == 'l')
		ft_print_d(param, ft_itoa_base((long)va_arg(ap, long), 10), buf);
	else if (param.length == 'l' + 'l')
		ft_print_d(param,
			ft_itoa_base((long long)va_arg(ap, long long), 10), buf);
	else
		return (0);
	return (1);
}

static int		ft_type_d_h_hh_check(t_param param, va_list ap, t_buf *buf)
{
	if (param.length == 'h')
		ft_print_d(param, ft_itoa_base((short)va_arg(ap, int), 10), buf);
	else if (param.length == 'h' + 'h')
		ft_print_d(param, ft_itoa_base((char)va_arg(ap, int), 10), buf);
	else
		return (0);
	return (1);
}

static int		ft_type_d_j_z_check(t_param param, va_list ap, t_buf *buf)
{
	if (param.length == 'j')
		ft_print_d(param, ft_itoa_base((intmax_t)
					va_arg(ap, intmax_t), 10), buf);
	else if (param.length == 'z')
		ft_print_d(param, ft_itoa_base((ssize_t)va_arg(ap, ssize_t), 10), buf);
	else
		return (0);
	return (1);
}

void			ft_type_d(t_param param, va_list ap, t_buf *buf)
{
	if (!(ft_type_d_l_ll_check(param, ap, buf)))
		if (!(ft_type_d_h_hh_check(param, ap, buf)))
			ft_type_d_j_z_check(param, ap, buf);
}
