/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:26:48 by bprincip          #+#    #+#             */
/*   Updated: 2019/10/24 12:35:14 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		turn_into_char(char *res, long long n,
								int base, int num_d)
{
	char	*buf;
	int		sign;

	buf = "0123456789abcdef";
	sign = 1;
	if (n < 0)
		sign = -1;
	res[num_d--] = '\0';
	while (n)
	{
		res[num_d--] = buf[(n % base) * sign];
		n /= base;
	}
}

char			*ft_itoa_base(long long n, int base)
{
	char	*res;
	int		num_d;

	if (base < 2 || base > 16)
		return (NULL);
	if (n == 0 || base == 10)
		res = ft_itoa(n);
	else
	{
		num_d = ft_num_dig(n, base);
		if (!(res = (char *)malloc(sizeof(char) * (num_d + 1))))
			return (NULL);
		turn_into_char(res, n, base, num_d);
	}
	return (res);
}
