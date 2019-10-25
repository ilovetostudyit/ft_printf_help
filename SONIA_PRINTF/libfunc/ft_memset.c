/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcummera <hcummera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 14:21:40 by hcummera          #+#    #+#             */
/*   Updated: 2019/01/06 21:49:15 by hcummera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../ft_printf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;

	if (len == 0)
		return (b);
	str = (unsigned char *)b;
	while (len--)
	{
		*str = (unsigned char)c;
		str++;
	}
	return (b);
}
