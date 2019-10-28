/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcummera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 01:16:46 by hcummera          #+#    #+#             */
/*   Updated: 2019/10/28 01:16:49 by hcummera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int				ft_param_fill(t_param *param, char **str, va_list ap)
{
	ft_get_flags(param, str);
	ft_get_width_main(param, str, ap);
	if (ft_get_prec_main(param, str, ap))
		return (-1);
	ft_get_length(param, str);
	ft_get_other_flags(param, str);
	return (1);
}
