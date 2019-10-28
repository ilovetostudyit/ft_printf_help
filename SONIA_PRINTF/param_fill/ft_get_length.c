/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcummera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 01:16:15 by hcummera          #+#    #+#             */
/*   Updated: 2019/10/28 01:16:16 by hcummera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_get_length(t_param *param, char **str)
{
	if (**str == 'L' || **str == 'l' || **str == 'h' ||
		**str == 'j' || **str == 'z')
	{
		param->length += **str;
		*str += 1;
	}
	if ((param->length == 'l' && **str == 'l') ||
		(param->length == 'h' && **str == 'h'))
	{
		param->length += **str;
		*str += 1;
	}
}
