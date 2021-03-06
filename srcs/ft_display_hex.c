/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:25:13 by tnave             #+#    #+#             */
/*   Updated: 2021/03/06 16:33:54 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char				is_hex(char c)
{
	return (c == 'x' || c == 'X');
}

int					ft_display_hex(t_pfstruct *pf, t_pfconv *c_conv)
{
	uintmax_t		nb;
	int				len;
	int				i;

	nb = va_arg(*pf->iter, unsigned int);
	len = ft_count_nbr(nb, 16);
	i = len;
	if (!ft_before_diux(pf, c_conv, nb, i))
		return (0);
	if (nb == 0 && c_conv->dot_prec >= 0)
		i--;
	else
	{
		if (pf->type == 'X')
			ft_putnbr_base(nb, "0123456789ABCDEF", pf);
		if (pf->type == 'x')
			ft_putnbr_base(nb, "0123456789abcdef", pf);
	}
	ft_after(pf, c_conv, i);
	return (0);
}
