/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcummera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 01:45:55 by hcummera          #+#    #+#             */
/*   Updated: 2019/10/28 01:45:56 by hcummera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void			ft_type_s(t_param param, char *ap, t_buf *buf)
{
	int	tmp;

	tmp = ft_strlen(ap);
	if (param.precision > -1 && param.minus == 0)
		ft_type_s_minus(param, ap, tmp, buf);
	else if (param.precision > -1 && param.minus != 0)
		ft_type_s_prec_pos(param, ap, tmp, buf);
	else
		ft_type_s_prec_neg(param, ap, tmp, buf);
}
