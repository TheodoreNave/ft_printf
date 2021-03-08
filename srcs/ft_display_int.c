/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:40:30 by tnave             #+#    #+#             */
/*   Updated: 2021/03/08 13:21:54 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char					is_int(char c)
{
	return (c == 'd' || c == 'i');
}

char					is_u_int(char c)
{
	return (c == 'u');
}

int						ft_display_int(t_pfstruct *pf, t_pfconv *c_conv)
{
	long				nb;
	long				i;
	long				len;

	nb = va_arg(*pf->iter, int);
	len = ft_count_nbr(nb, 10);
	i = len;
	if (!ft_before_diux(pf, c_conv, nb, i))
		return (0);
	if (nb == 0 && c_conv->dot_prec >= 0)
		i--;
	else
		pf_putnbr(pf, nb);
	ft_after(pf, c_conv, i);
	return (0);
}

int						ft_display_u_int(t_pfstruct *pf, t_pfconv *c_conv)
{
	unsigned int		nb;
	long				len;
	long				i;

	nb = va_arg(*pf->iter, unsigned int);
	len = ft_count_nbr(nb, 10);
	i = len;
	if (!ft_before_diux(pf, c_conv, nb, i))
		return (0);
	if (nb == 0 && c_conv->dot_prec >= 0)
		i--;
	else
		pf_putnbr(pf, nb);
	ft_after(pf, c_conv, i);
	return (0);
}
