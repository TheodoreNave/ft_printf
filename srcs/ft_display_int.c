/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:40:30 by tnave             #+#    #+#             */
/*   Updated: 2021/03/01 16:04:37 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	is_int(char c)
{
	return (c == 'd' || c == 'i');
}

char	is_u_int(char c)
{
	return (c == 'u');
}

int		ft_display_int(t_pfstruct *type, t_pfconv c_conv, va_list iter)
{
	int		nb;
	int 	len;
	int		i;
	int		neg;
	
	nb = va_arg(iter, int);
	len = ft_count_nbr(nb, 10);					//= 2
	i = len;
	neg = 0;
	// printf("len of nb = %d\n", i);
	// printf("dot = %d\n", c_conv.dot);
	// printf("zero = %d\n", c_conv.zero);
	// printf("dash = %d\n", c_conv.dash);
	// printf("width = %d\n", c_conv.width);
	// printf("prec = %d\n", c_conv.prec);

	if (nb < 0)
	{
		nb = -nb;
		neg = 1;
		c_conv.prec++;
	}
	if (nb == 0 && c_conv.prec == 0)
	{
		ft_padding(' ', type, c_conv.width - (ft_max(len, c_conv.prec)));
		add_to_buff(type, ' ');
		return (0);
	}
	if (c_conv.prec >= 0 && c_conv.zero == 1)
	{
		c_conv.zero = 0;
		c_conv.dash = 0;
	}
	if (c_conv.dash == 0 && c_conv.zero == 0)
		ft_padding(' ', type, c_conv.width - (ft_max(len, c_conv.prec)));
	if (neg)
		add_to_buff(type, '-');
	ft_padding('0', type, c_conv.prec - len);
	if (c_conv.zero == 1 && c_conv.dot == 0)
		ft_padding('0', type, c_conv.width - (ft_max(len, c_conv.prec)));
	pf_putnbr(type, nb);
	if (c_conv.dash == 1)
		ft_padding(' ', type, c_conv.width - (ft_max(len, c_conv.prec)));
	return (0);
}

int				ft_display_u_int(t_pfstruct *type, t_pfconv c_conv, va_list iter)
{
	unsigned int		nb;
	long				len;
	long				i;
	long				neg;
	
	nb = va_arg(iter, unsigned int);
	len = ft_count_nbr(nb, 10);					//= 2
	i = len;
	neg = 0;
	// printf("len of nb = %ld\n", i);
	// printf("dot = %d\n", c_conv.dot);
	// printf("zero = %d\n", c_conv.zero);
	// printf("dash = %d\n", c_conv.dash);
	// printf("width = %d\n", c_conv.width);
	// printf("prec = %d\n", c_conv.prec);
	if (nb == 0 && c_conv.prec == 0)
	{
		ft_padding(' ', type, c_conv.width - (ft_max(len, c_conv.prec)));
		return (0);
	}
	if (c_conv.dash == 0 && c_conv.zero == 0)
		ft_padding(' ', type, c_conv.width - (ft_max(len, c_conv.prec)));
	ft_padding('0', type, c_conv.prec - len);
	if (c_conv.zero == 1)
		ft_padding('0', type, c_conv.width - (ft_max(len, c_conv.prec)));
	pf_putnbr(type, nb);
	if (c_conv.dash == 1)
		ft_padding(' ', type, c_conv.width - (ft_max(len, c_conv.prec)));
	return (0);
}