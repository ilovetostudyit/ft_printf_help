/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcummera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 01:46:05 by hcummera          #+#    #+#             */
/*   Updated: 2019/10/28 01:46:11 by hcummera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void		u_prec_tmp_check(t_param param, t_buf *buf, int tmp)
{
	if (param.precision > tmp)
		ft_buf_add_s(buf, ft_memnew(param.precision - tmp, '0'), 0, 1);
}
