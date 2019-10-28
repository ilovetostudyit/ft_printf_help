/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcummera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 01:42:52 by hcummera          #+#    #+#             */
/*   Updated: 2019/10/28 01:42:54 by hcummera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_tire_check(char *str, t_buf *buf)
{
	if (*str == '-')
		ft_print_else(buf, '-');
}

void	ft_space_check(char *str, t_param *param, t_buf *buf)
{
	if (param->space == 1 && param->plus == 0 && *str != '-')
		ft_print_else(buf, ' ');
	else
		param->space = 0;
}

void	ft_plus_check(char *str, t_param *param, t_buf *buf)
{
	if (param->plus == 1 && *str != '-')
		ft_print_else(buf, '+');
}

void	ft_zero_check(char *str, t_param *param, t_buf *buf)
{
	if (!(*str == '0' && param->precision == 0))
		ft_buf_add_s(buf, str, 0, 1);
}
