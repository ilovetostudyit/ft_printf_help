/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcummera <hcummera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:27:07 by hcummera          #+#    #+#             */
/*   Updated: 2019/01/30 22:05:39 by hcummera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int				ft_getsign(const char *str, unsigned long i)
{
	if (str[i] == '-')
		return (-1);
	else if (str[i] == '+')
		return (1);
	return (2);
}

static unsigned long	ft_removesp(const char *str, unsigned long i)
{
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	return (i);
}

int						ft_atoi(const char *str)
{
	unsigned long	i;
	unsigned long	nbr;
	int				sign;

	nbr = 0;
	i = ft_removesp(str, 0);
	sign = ft_getsign(str, i);
	if (sign == 1 || sign == -1)
		i++;
	else
		sign = 1;
	while (str[i] == 0)
		i++;
	while (ft_isdigit(str[i]))
	{
		nbr = nbr * 10;
		nbr = nbr + (int)str[i] - '0';
		i++;
		if (nbr != (nbr * 10 / 10) && sign == 1)
			return (-1);
		if (nbr != (nbr * 10 / 10) && sign == -1)
			return (0);
	}
	return (nbr * sign);
}
