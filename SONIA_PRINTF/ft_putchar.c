/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:29:38 by bprincip          #+#    #+#             */
/*   Updated: 2019/10/24 16:22:03 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_two_b(unsigned long long c, char *str)
{
	str[1] = (c & 63) | (2 << 6);
	str[0] = ((c >> 6) & 31) | (6 << 5);
}

void	ft_three_b(unsigned long long c, char *str)
{
	str[2] = (c & 63) | (2 << 6);
	str[1] = ((c >> 6) & 63) | (2 << 6);
	str[0] = ((c >> 12) & 15) | (14 << 4);
}

void	ft_four_b(unsigned long long c, char *str)
{
	str[3] = (c & 63) | (2 << 6);
	str[2] = ((c >> 6) & 63) | (2 << 6);
	str[1] = ((c >> 12) & 63) | (2 << 6);
	str[0] = ((c >> 18) & 7) | (30 << 3);
}

int		ft_putchar(unsigned long long c, char *str)
{
	if (c <= 127)
	{
		*str = (char)c;
		return (1);
	}
	else if (c <= 2047)
	{
		ft_two_b(c, str);
		return (2);
	}
	else if (c <= 65535)
	{
		ft_three_b(c, str);
		return (3);
	}
	else
	{
		ft_four_b(c, str);
		return (4);
	}
}