/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_dota.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:53:45 by bprincip          #+#    #+#             */
/*   Updated: 2019/10/27 23:26:24 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char	*un(char *main, char *s)
{
	char	*tmp_c;

	tmp_c = main;
	if (*s == '-')
		main = ft_strjoin(s, main);
	else
		main = ft_strjoin(main, s);
	free(tmp_c);
	return (main);
}

int		max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
