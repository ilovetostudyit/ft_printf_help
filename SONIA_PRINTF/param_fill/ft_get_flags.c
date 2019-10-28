/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcummera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 01:16:04 by hcummera          #+#    #+#             */
/*   Updated: 2019/10/28 01:16:08 by hcummera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_get_flags(t_param *param, char **str)
{
	while (**str && (**str == '0' || **str == '+' || **str == '-' ||
			**str == ' ' || **str == '#'))
	{
		(**str == '#') ? param->hash = 1 : 0;
		(**str == '-') ? param->minus = 1 : 0;
		(**str == '+') ? param->plus = 1 : 0;
		(**str == ' ') ? param->space = 1 : 0;
		(**str == '0') ? param->zero = 1 : 0;
		*str += 1;
	}
	(param->space == 1 && param->plus == 1) ? param->space = 0 : 1;
	(param->zero == 1 && param->minus == 1) ? param->zero = 0 : 1;
}

void	ft_get_other_flags(t_param *param, char **str)
{
	if (**str && (**str == '0' || **str == '+' || **str == '-' ||
			**str == ' ' || **str == '#'))
		ft_get_flags(param, str);
}
