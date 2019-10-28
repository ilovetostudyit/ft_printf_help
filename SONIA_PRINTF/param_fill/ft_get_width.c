/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcummera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 01:16:35 by hcummera          #+#    #+#             */
/*   Updated: 2019/10/28 01:16:39 by hcummera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_get_width_main(t_param *param, char **str, va_list ap)
{
	ft_get_width(param, str, ap);
	if (**str == '*' || (**str >= '0' && **str <= '9'))
		ft_get_width(param, str, ap);
}

int		ft_get_width(t_param *param, char **str, va_list ap)
{
	if (**str == '*')
	{
		param->width = (long long)va_arg(ap, long long);
		if (param->width < 0)
		{
			param->width *= -1;
			param->minus = 1;
		}
		*str = *str + 1;
	}
	else
	{
		param->width = ft_atoi(*str);
		while (**str && **str >= '0' && **str <= '9')
			*str += 1;
	}
	return (0);
}
