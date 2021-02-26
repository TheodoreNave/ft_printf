/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:25:13 by tnave             #+#    #+#             */
/*   Updated: 2021/02/24 13:27:17 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	add_str_to_buff(pfstruct *pf, char *str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		add_to_buff(pf, str[i]);
		i++;
	}
}

int		ft_display_hex(pfstruct *type, pfconv c_conv, va_list iter)
{
	uintmax_t		nb;
	int				len;
	int				i;
	int				neg;
	
	nb = va_arg(iter, unsigned int);
	len = ft_count_nbr(nb, 16);					//= 2
	i = len;
	neg = 0;
	
	// printf("\n");
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
	if (c_conv.dash == 0 && c_conv.zero == 0)
		padding(' ', type, c_conv.width - (max(len, c_conv.prec)));
	if (neg)
		add_to_buff(type, '-');
	padding('0', type, c_conv.prec - len);
	if (c_conv.zero == 1)
		padding('0', type, c_conv.width - (max(len, c_conv.prec)));
	if (type->type == 'X')
		ft_putnbr_base(nb, "0123456789ABCDEF", type);
	if (type->type == 'x')
		ft_putnbr_base(nb, "0123456789abcdef", type);
	if (c_conv.dash == 1)
		padding(' ', type, c_conv.width - (max(len, c_conv.prec)));
	return (0);
}