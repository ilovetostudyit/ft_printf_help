/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:30:40 by bprincip          #+#    #+#             */
/*   Updated: 2019/10/16 16:33:37 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

static void		*ft_memalloc(size_t size)
{
	void	*new;

	new = NULL;
	if (size != 0)
	{
		if (!(new = (void *)malloc(size)))
			return (NULL);
		ft_bzero(new, size);
	}
	return (new);
}

char			*ft_strnew(size_t size)
{
	return ((char *)ft_memalloc(size + 1));
}
