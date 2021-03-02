/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:40:30 by tnave             #+#    #+#             */
/*   Updated: 2021/03/02 15:22:54 by tnave            ###   ########.fr       */
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
	len = ft_count_nbr(nb, 10);
	i = len;
	neg = 0;

	if (nb <= INT_MIN)
	{
			add_str_to_buff(type, "-2147483648");
			return (0);
	}
	if (nb >= INT_MAX)
	{
			add_str_to_buff(type, "2147483647");
			return (0);
	}
	if (nb < 0)
	{
		nb = -nb;
		neg = 1;
		c_conv.prec++;
	}
	
	if (nb == 0 && c_conv.dot == 1 && c_conv.prec == 0 && c_conv.width == 0)
	{
		return (0);
	}
	if (c_conv.dash == 0 && c_conv.width < 0 && c_conv.prec == -1 && c_conv.dot == 1 && nb == 0)
	{
		return (0);
	}
	if (c_conv.width > 0 && c_conv.dot == 1 && c_conv.prec == 0 && nb == 0)
	{
		ft_padding(' ', type, c_conv.width);
		return (0);
	}
	if (c_conv.width > 0 && c_conv.dot == 1 && c_conv.prec == -1)
	{
		ft_padding(' ', type, c_conv.width);
		return (0);
	}
	if (c_conv.prec > 0 && c_conv.zero == 1)
	{
		c_conv.zero = 0;
		c_conv.dash = 0;
	}
	if (c_conv.dash == 0 && c_conv.zero == 0)
		ft_padding(' ', type, c_conv.width - (ft_max(len, c_conv.prec)));
	if (neg && ((nb != INT_MIN || nb != INT_MAX)))
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

	// if (nb == 0 && c_conv.prec == 0)
	// {
	// 	ft_padding(' ', type, c_conv.width - (ft_max(len, c_conv.prec)));
	// 	return (0);
	// }
	// if (c_conv.dash == 0 && c_conv.zero == 0)
	// 	ft_padding(' ', type, c_conv.width - (ft_max(len, c_conv.prec)));
	// ft_padding('0', type, c_conv.prec - len);
	// if (c_conv.zero == 1)
	// 	ft_padding('0', type, c_conv.width - (ft_max(len, c_conv.prec)));
	// pf_putnbr(type, nb);
	// if (c_conv.dash == 1)
	// 	ft_padding(' ', type, c_conv.width - (ft_max(len, c_conv.prec)));
	// return (0);


	if (nb == 0 && c_conv.dot == 1 && c_conv.prec == 0 && c_conv.width == 0)
	{
		return (0);
	}
	if (c_conv.dash == 0 && c_conv.width < 0 && c_conv.prec == -1 && c_conv.dot == 1 && nb == 0)
	{
		return (0);
	}
	if (c_conv.width > 0 && c_conv.dot == 1 && c_conv.prec == 0 && nb == 0)
	{
		ft_padding(' ', type, c_conv.width);
		return (0);
	}
	if (c_conv.width > 0 && c_conv.dot == 1 && c_conv.prec == -1)
	{
		ft_padding(' ', type, c_conv.width);
		return (0);
	}
	if (c_conv.prec > 0 && c_conv.zero == 1)
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