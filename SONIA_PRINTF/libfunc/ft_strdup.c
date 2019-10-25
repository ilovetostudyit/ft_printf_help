/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcummera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 14:11:45 by hcummera          #+#    #+#             */
/*   Updated: 2019/01/27 17:31:35 by hcummera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../ft_printf.h"

char	*ft_strdup(const char *src)
{
	int		length;
	char	*string;
	int		i;

	length = ft_strlen(src);
	i = 0;
	string = (char*)malloc(sizeof(*string) * (length + 1));
	if (!string)
		return (NULL);
	while (i < length)
	{
		string[i] = src[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}
