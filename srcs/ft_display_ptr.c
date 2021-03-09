/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:25:15 by tnave             #+#    #+#             */
/*   Updated: 2021/03/09 23:57:03 by tnave            ###   ########.fr       */
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
	if (!print_begin(pf, c_co, nb, len))
		return (0);
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
