/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcummera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 01:47:11 by hcummera          #+#    #+#             */
/*   Updated: 2019/10/28 01:47:12 by hcummera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static int		ft_type_u_l_ll_check(t_param param, va_list ap, t_buf *buf)
{
	if (param.length == 0)
		ft_print_u(param,
		ft_itoa_base_ll((unsigned)va_arg(ap, unsigned), 10), buf);
	else if (param.length == 'l')
		ft_print_u(param,
		ft_itoa_base_ll((unsigned long)va_arg(ap, unsigned long), 10), buf);
	else if (param.length == 'l' + 'l')
		ft_print_u(param,
		ft_itoa_base_ll((unsigned long long)va_arg(ap, unsigned long long),
		10), buf);
	else
		return (0);
	return (1);
}

static int		ft_type_u_h_hh_check(t_param param, va_list ap, t_buf *buf)
{
	if (param.length == 'h')
		ft_print_u(param,
			ft_itoa_base_ll((unsigned short)va_arg(ap, unsigned), 10), buf);
	else if (param.length == 'h' + 'h')
		ft_print_u(param,
				ft_itoa_base_ll((unsigned char)va_arg(ap, unsigned), 10), buf);
	else
		return (0);
	return (1);
}

static int		ft_type_u_j_z_check(t_param param, va_list ap, t_buf *buf)
{
	if (param.length == 'j')
		ft_print_u(param,
				ft_itoa_base_ll((uintmax_t)va_arg(ap, uintmax_t), 10), buf);
	else if (param.length == 'z')
		ft_print_u(param, ft_itoa_base_ll((size_t)va_arg(ap, size_t), 10), buf);
	else
		return (0);
	return (1);
}

void			ft_type_u(t_param param, va_list ap, t_buf *buf)
{
	if (!(ft_type_u_l_ll_check(param, ap, buf)))
		if (!(ft_type_u_h_hh_check(param, ap, buf)))
			ft_type_u_j_z_check(param, ap, buf);
}
