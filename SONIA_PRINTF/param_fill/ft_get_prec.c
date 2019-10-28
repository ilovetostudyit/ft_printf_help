/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_prec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcummera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 01:16:23 by hcummera          #+#    #+#             */
/*   Updated: 2019/10/28 01:16:25 by hcummera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_get_prec_main(t_param *param, char **str, va_list ap)
{
	if (**str == '.')
		if ((ft_get_prec(param, str, ap)) == -1)
			return (-1);
	return (0);
}

int		ft_get_prec(t_param *param, char **str, va_list ap)
{
	if (*(*str + 1) >= '0' && *(*str + 1) <= '9')
		param->precision = ft_atoi(*str + 1);
	else if (*(*str + 1) == '-')
		param->precision = -2;
	else if (*(*str + 1) == '*')
	{
		param->precision = (unsigned long long)va_arg(ap, unsigned long long);
		*str = *str + 1;
	}
	else if (*(*str + 1) == '\0')
		return (-1);
	else
		param->precision = 0;
	*str += 1;
	while (**str && **str >= '0' && **str <= '9')
		*str += 1;
	return (1);
	return (0);
}
