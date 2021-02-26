/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:40:30 by tnave             #+#    #+#             */
/*   Updated: 2021/02/24 15:00:10 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			pf_putnbr(pfstruct *type, long nb)
{
	if (nb < 0)
	{
		add_to_buff(type, '-');
		nb *= -1;
	}
	if (nb >= 10)
		pf_putnbr(type, nb / 10);
	add_to_buff(type, nb % 10 + '0');
	return (0);
}

void			padding(char c, pfstruct *type, long len)
{
	while (len-- > 0)
		add_to_buff(type, c);
}

int				max(long a, long b)
{
	if (a > b)
		return (a);
	else
		return (b);
	
}

int				ft_display_int(pfstruct *type, pfconv c_conv, va_list iter)
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
		padding(' ', type, c_conv.width - (max(len, c_conv.prec)));
		return (0);
	}
	if (c_conv.prec >= 0 && c_conv.zero == 1)
	{
		c_conv.zero = 0;
		c_conv.dash = 0;
	}
	if (c_conv.dash == 0 && c_conv.zero == 0)
		padding(' ', type, c_conv.width - (max(len, c_conv.prec)));
	if (neg)
		add_to_buff(type, '-');
	
		padding('0', type, c_conv.prec - len);
	if (c_conv.zero == 1)
		padding('0', type, c_conv.width - (max(len, c_conv.prec)));
	pf_putnbr(type, nb);
	if (c_conv.dash == 1)
		padding(' ', type, c_conv.width - (max(len, c_conv.prec)));
	return (0);
}

int				ft_display_u_int(pfstruct *type, pfconv c_conv, va_list iter)
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
		padding(' ', type, c_conv.width - (max(len, c_conv.prec)));
		return (0);
	}
	if (c_conv.dash == 0 && c_conv.zero == 0)
		padding(' ', type, c_conv.width - (max(len, c_conv.prec)));
	padding('0', type, c_conv.prec - len);
	if (c_conv.zero == 1)
		padding('0', type, c_conv.width - (max(len, c_conv.prec)));
	pf_putnbr(type, nb);
	if (c_conv.dash == 1)
		padding(' ', type, c_conv.width - (max(len, c_conv.prec)));
	return (0);
}