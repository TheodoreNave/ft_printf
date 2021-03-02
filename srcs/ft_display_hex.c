/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:25:13 by tnave             #+#    #+#             */
/*   Updated: 2021/03/02 20:21:55 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char 	is_hex(char c)
{
	return (c == 'x' || c == 'X');
}

int		ft_display_hex(t_pfstruct *type, t_pfconv c_conv, va_list iter)
{
	uintmax_t		nb;
	int				len;
	int				i;
	int				neg;
	
	nb = va_arg(iter, unsigned int);
	len = ft_count_nbr(nb, 16);					//= 2
	i = len;
	neg = 0;

	if (nb < 0)
	{
		nb = -nb;
		neg = 1;
		c_conv.dot_prec++;
	}
		// printf("len = %d\n", len);

	if (c_conv.dot == 1 && c_conv.dot_prec < 0)
		c_conv.dot = 0;

	if (c_conv.dash == 1 && c_conv.nb_width > 0 && c_conv.dot_prec == 0 && nb == 0)
	{
		ft_padding(' ', type, c_conv.nb_width);
		return (0);
	}
	if (nb == 0 && c_conv.dot_prec == 0 && c_conv.dash == 1)
	{
		ft_padding(' ', type, c_conv.nb_width - (ft_max(len, c_conv.dot_prec)));
		add_to_buff(type, ' ');
		return (0);
	}
	if (c_conv.zero == 1 && c_conv.nb_width > c_conv.dot_prec && c_conv.dot_prec > 0)
	{
		ft_padding(' ', type, c_conv.nb_width - (ft_max(len, c_conv.dot_prec)));
		ft_padding('0', type, c_conv.dot_prec - len);
	}
	if (nb == 0 && c_conv.dot_prec == 0 && c_conv.dash == 0 && c_conv.nb_width > 0)
	{
		ft_padding(' ', type, c_conv.nb_width - (ft_max(len, c_conv.dot_prec)));
		add_to_buff(type, ' ');
		return (0);
	}
	if (nb == 0 && c_conv.dot_prec == 0 && c_conv.dash == 0)
	{
		ft_padding(' ', type, c_conv.nb_width - (ft_max(len, c_conv.dot_prec)));
		return (0);
	}
	if (c_conv.zero == 1 && c_conv.nb_width >= c_conv.dot_prec && c_conv.dot == 1 && c_conv.dot_prec >= 1)
	{
		// ft_padding(' ', type, c_conv.nb_width - (ft_max(len, c_conv.dot_prec)));
		if (type->type == 'X')
			ft_putnbr_base(nb, "0123456789ABCDEF", type);
		if (type->type == 'x')
			ft_putnbr_base(nb, "0123456789abcdef", type);
		return (0);
	}
	if (c_conv.dash == 0 && c_conv.zero == 0)
		ft_padding(' ', type, c_conv.nb_width - (ft_max(len, c_conv.dot_prec)));
	if (neg)
		add_to_buff(type, '-');
	ft_padding('0', type, c_conv.dot_prec - len);
	if (c_conv.zero == 1)
		ft_padding('0', type, c_conv.nb_width - (ft_max(len, c_conv.dot_prec)));
	if (c_conv.zero == 1 && c_conv.nb_width < c_conv.dot_prec)
	{
		ft_padding('0', type, c_conv.nb_width - (ft_max(len, c_conv.dot_prec)));
	}
	if (type->type == 'X')
		ft_putnbr_base(nb, "0123456789ABCDEF", type);
	if (type->type == 'x')
		ft_putnbr_base(nb, "0123456789abcdef", type);
	if (c_conv.dash == 1)
		ft_padding(' ', type, c_conv.nb_width - (ft_max(len, c_conv.dot_prec)));
	return (0);
}