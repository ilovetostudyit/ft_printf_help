/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcummera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 01:44:19 by hcummera          #+#    #+#             */
/*   Updated: 2019/10/28 01:44:21 by hcummera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_zero_m_e(char **main, char **frac)
{
	*main = ft_itoa(0);
	*frac = ft_itoa(0);
}

void	ft_len_frac_more_prec(int tmp, int prec, char **frac)
{
	char			*tmp_c;
	char			*tmp_prec;

	tmp_c = ft_memnew(prec - tmp, '0');
	tmp_prec = *frac;
	*frac = ft_strjoin(tmp_prec, tmp_c);
	free(tmp_prec);
	free(tmp_c);
}
