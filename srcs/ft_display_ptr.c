/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:25:15 by tnave             #+#    #+#             */
/*   Updated: 2021/03/08 18:58:06 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char				is_ptr(char c)
{
	return (c == 'p');
}

int					ft_display_ptr(t_pfstruct *pf, t_pfconv *c_co)
{
	uintptr_t		nb;
	int				i;
	int				len;

	nb = (uintptr_t)va_arg(*pf->iter, uintptr_t);
	i = ft_count_nbr(nb, 16);
	len = i + 2;
	if (nb == 0 && c_co->dot_prec == 0)
	{
		ft_padding(' ', pf, c_co->nb_width - (ft_max(--len, c_co->dot_prec)));
		add_str_to_buff(pf, "0x");
		return (0);
	}
	if (c_co->dash == 0 && c_co->zero == 0)
		ft_padding(' ', pf, c_co->nb_width - (ft_max(len, c_co->dot_prec)));
	ft_padding('0', pf, c_co->dot_prec - len);
	if (nb != 0)
	{
		add_str_to_buff(pf, "0x");
		ft_putnbr_base(nb, "0123456789abcdef", pf);
	}
	else
		add_str_to_buff(pf, "0x0");
	ft_after(pf, c_co, len);
	return (0);
}
