/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:25:15 by tnave             #+#    #+#             */
/*   Updated: 2021/02/24 13:27:02 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_display_ptr(pfstruct *type, pfconv c_conv, va_list iter)
{
	uintmax_t		nb;
	int 			i;
	int				len;
	
	nb = (uintmax_t)va_arg(iter, void *);
	i = ft_count_nbr(nb, 16);
	len = i + 2;
	if (nb == 0 && c_conv.prec == 0)
	{
		padding(' ', type, c_conv.width - (max(len, c_conv.prec)));
		return (0);
	}
	if (c_conv.dash == 0 && c_conv.zero == 0)
		padding(' ', type, c_conv.width - (max(len, c_conv.prec)));
	padding('0', type, c_conv.prec - len);
	add_str_to_buff(type, "0x");
	ft_putnbr_base(nb, "0123456789abcdef", type);
	if (c_conv.dash == 1)
		padding(' ', type, c_conv.width - (max(len, c_conv.prec)));
	return (0);
}