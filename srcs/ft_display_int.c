/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:40:30 by tnave             #+#    #+#             */
/*   Updated: 2021/03/04 19:56:24 by tnave            ###   ########.fr       */
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

int		ft_display_int(t_pfstruct *pf, t_pfconv *c_conv)
{
	long		nb;
	long		i;
	long		len;

	nb = va_arg(*pf->iter, int);
	len = ft_count_nbr(nb, 10);
	i = len;

	if (nb <= INT_MIN)
	{
			add_str_to_buff(pf, "-2147483648");
			return (0);
	}
	if (nb >= INT_MAX)
	{
			add_str_to_buff(pf, "2147483647");
			return (0);
	}
	if (!(ft_before_diux(pf, c_conv, nb, i)))
		return (0);
	pf_putnbr(pf, nb);
	ft_after(pf, c_conv, i);
	return (0);
}


int				ft_display_u_int(t_pfstruct *pf, t_pfconv *c_conv)
{
	unsigned int		nb;
	long				len;
	long				i;

	nb = va_arg(*pf->iter, unsigned int);
	len = ft_count_nbr(nb, 10);
	i = len;

	
	if (!(ft_before_diux(pf, c_conv, nb, i)))
		return (0);
	pf_putnbr(pf, nb);
	ft_after(pf, c_conv, i);
	return (0);
}