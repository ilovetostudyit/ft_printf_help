/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:30:14 by bprincip          #+#    #+#             */
/*   Updated: 2019/10/24 13:05:36 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	char *tmp;

	if (s)
	{
		tmp = (char*)s;
		if (s)
			while (*tmp)
				tmp++;
		return (tmp - s);
	}
	return (0);
}
