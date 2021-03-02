/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:26:23 by tnave             #+#    #+#             */
/*   Updated: 2021/03/02 13:54:14 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

	// printf("\n");
	// printf("len of nb = %d\n", i);
	// printf("dot = %d\n", c_conv.dot);
	// printf("zero = %d\n", c_conv.zero);
	// printf("dash = %d\n", c_conv.dash);
	// printf("width = %d\n", c_conv.width);
	// printf("prec = %d\n", c_conv.prec);

size_t		ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


int			pf_putnbr(t_pfstruct *type, long nb)
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

void		ft_padding(char c, t_pfstruct *type, long len)
{
	while (len > 0)
	{
		add_to_buff(type, c);
		len--;
	}
}

int			ft_max(long a, long b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void		*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*pb;

	pb = b;
	while (len > 0)
	{
		*pb = c;
		pb++;
		len--;
	}
	return (b);
}