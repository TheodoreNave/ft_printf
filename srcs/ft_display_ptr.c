/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:25:15 by tnave             #+#    #+#             */
/*   Updated: 2021/03/06 16:35:33 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char				is_ptr(char c)
{
	return (c == 'p');
}

int					ft_display_ptr(t_pfstruct *pf, t_pfconv *c_conv)
{
	uintmax_t		nb;
	int				i;
	int				len;

	nb = (uintmax_t)va_arg(*pf->iter, void *);
	i = ft_count_nbr(nb, 16);
	len = i + 2;
	if (nb == 0 && c_conv->dot_prec == 0)
	{
		ft_padding(' ', pf, c_conv->nb_width - (ft_max(len, c_conv->dot_prec)));
		return (0);
	}
	if (c_conv->dash == 0 && c_conv->zero == 0)
		ft_padding(' ', pf, c_conv->nb_width - (ft_max(len, c_conv->dot_prec)));
	ft_padding('0', pf, c_conv->dot_prec - len);
	add_str_to_buff(pf, "0x");
	ft_putnbr_base(nb, "0123456789abcdef", pf);
	if (c_conv->dash == 1)
		ft_padding(' ', pf, c_conv->nb_width - (ft_max(len, c_conv->dot_prec)));
	return (0);
}
