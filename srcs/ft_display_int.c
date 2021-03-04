/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:40:30 by tnave             #+#    #+#             */
/*   Updated: 2021/03/04 15:09:25 by tnave            ###   ########.fr       */
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
	// int			neg;
	long		len;

	nb = va_arg(*pf->iter, int);
	len = ft_count_nbr(nb, 10);
	i = len;
	// neg = 0;

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
	// if (nb == 0 && c_conv->dot == 1 && c_conv->dot_prec == 0 && c_conv->nb_width == 0)
	// 	return (0);
	// if (c_conv->dash == 0 && c_conv->nb_width < 0 && c_conv->dot_prec == -1 && c_conv->dot == 1 && nb == 0)
	// 	return (0);
	// if (c_conv->nb_width > 0 && c_conv->dot == 1 && c_conv->dot_prec == 0 && nb == 0)
	// {
	// 	ft_padding(' ', pf, c_conv->nb_width);
	// 	return (0);
	// }
	// if (c_conv->nb_width > 0 && c_conv->dot == 1 && c_conv->dot_prec == -1)
	// {
	// 	ft_padding(' ', pf, c_conv->nb_width);
	// 	return (0);
	// }
	// if (c_conv->dot_prec > 0 && c_conv->zero == 1)
	// {
	// 	c_conv->zero = 0;
	// 	c_conv->dash = 0;
	// }
	// if (c_conv->dash == 0 && c_conv->zero == 0)
	// 	ft_padding(' ', pf, c_conv->nb_width - (ft_max(i, c_conv->dot_prec)));
	// if (neg && ((nb != INT_MIN || nb != INT_MAX)))
	// 	add_to_buff(pf, '-');
	// ft_padding('0', pf, c_conv->dot_prec - i);
	// if (c_conv->zero == 1 && c_conv->dot == 0)
	// 	ft_padding('0', pf, c_conv->nb_width - (ft_max(i, c_conv->dot_prec)));
		
	// if (neg && ((nb != INT_MIN || nb != INT_MAX)))
	// 	add_to_buff(pf, '-');

		
	pf_putnbr(pf, nb);
	ft_after(pf, c_conv, nb, i);
	return (0);

}



































// ===============+NOT THIS ONE

int				ft_display_u_int(t_pfstruct *pf, t_pfconv *c_conv)
{
	unsigned int		nb;
	long				len;
	long				i;
	long				neg;

	nb = va_arg(*pf->iter, unsigned int);
	len = ft_count_nbr(nb, 10);					//= 2
	i = len;
	neg = 0;

	
	if (nb == 0 && c_conv->dot_prec == 0)
	{
		ft_padding(' ', pf, c_conv->nb_width - (ft_max(len, c_conv->dot_prec)));
		return (0);
	}
	if (c_conv->dot_prec > 0 && c_conv->zero == 1)
	{
		c_conv->zero = 0;
		c_conv->dash = 0;
	}
	if (c_conv->dash == 0 && c_conv->zero == 0)
		ft_padding(' ', pf, c_conv->nb_width - (ft_max(len, c_conv->dot_prec)));
	ft_padding('0', pf, c_conv->dot_prec - len);
	if (c_conv->zero == 1)
		ft_padding('0', pf, c_conv->nb_width - (ft_max(len, c_conv->dot_prec)));
	pf_putnbr(pf, nb);
	if (c_conv->dash == 1)
		ft_padding(' ', pf, c_conv->nb_width - (ft_max(len, c_conv->dot_prec)));
	return (0);

}

// ===============+NOT THIS ONE












// 	if (nb == 0 && c_conv->dot == 1 && c_conv->dot_prec == 0 && c_conv->nb_width == 0)
// 	{
// 		return (0);
// 	}
// 	if (c_conv->dash == 0 && c_conv->nb_width < 0 && c_conv->dot_prec == -1 && c_conv->dot == 1 && nb == 0)
// 	{
// 		return (0);
// 	}
// 	if (c_conv->nb_width > 0 && c_conv->dot == 1 && c_conv->dot_prec == 0 && nb == 0)
// 	{
// 		ft_padding(' ', pf, c_conv->nb_width);
// 		return (0);
// 	}
// 	if (c_conv->nb_width > 0 && c_conv->dot == 1 && c_conv->dot_prec == -1)
// 	{
// 		ft_padding(' ', pf, c_conv->nb_width);
// 		return (0);
// 	}
// 	if (c_conv->dot_prec > 0 && c_conv->zero == 1)
// 	{
// 		c_conv->zero = 0;
// 		c_conv->dash = 0;
// 	}
// 	if (c_conv->dash == 0 && c_conv->zero == 0)
// 		ft_padding(' ', pf, c_conv->nb_width - (ft_max(len, c_conv->dot_prec)));
// 	if (neg)
// 		add_to_buff(pf, '-');
// 	ft_padding('0', pf, c_conv->dot_prec - len);
// 	if (c_conv->zero == 1 && c_conv->dot == 0)
// 		ft_padding('0', pf, c_conv->nb_width - (ft_max(len, c_conv->dot_prec)));
// 	pf_putnbr(pf, nb);
// 	if (c_conv->dash == 1)
// 		ft_padding(' ', pf, c_conv->nb_width - (ft_max(len, c_conv->dot_prec)));
// 	return (0);
// }











// ==================================NB 
// if (neg && ((nb != INT_MIN || nb != INT_MAX)))
	// 	add_to_buff(pf, '-');
	// ft_padding('0', pf, c_conv->dot_prec - i);
	// // if (c_conv->zero == 1 && c_conv->dot_prec == 0)
	// // 	ft_padding('0', pf, c_conv->nb_width - (ft_max(len, c_conv->dot_prec)));
	// ft_before_diux(pf, c_conv, nb, i);
	// pf_putnbr(pf, nb);
	// if (c_conv->dash == 1)
	// {
	// 	ft_padding(' ', pf, c_conv->nb_width - (ft_max(i, c_conv->dot_prec)));
	// 	return (0);
	// }
	// return (0);
















// 	if (nb == 0 && c_conv->dot == 1 && c_conv->dot_prec == 0 && c_conv->nb_width == 0)
// 	{
// 		return (0);
// 	}
// 	if (c_conv->dash == 0 && c_conv->nb_width < 0 && c_conv->dot_prec == -1 && c_conv->dot == 1 && nb == 0)
// 	{
// 		return (0);
// 	}
// 	if (c_conv->nb_width > 0 && c_conv->dot == 1 && c_conv->dot_prec == 0 && nb == 0)
// 	{
// 		ft_padding(' ', pf, c_conv->nb_width);
// 		return (0);
// 	}
// 	if (c_conv->nb_width > 0 && c_conv->dot == 1 && c_conv->dot_prec == -1)
// 	{
// 		ft_padding(' ', pf, c_conv->nb_width);
// 		return (0);
// 	}
// 	if (c_conv->dot_prec > 0 && c_conv->zero == 1)
// 	{
// 		c_conv->zero = 0;
// 		c_conv->dash = 0;
// 	}
// 	if (c_conv->dash == 0 && c_conv->zero == 0)
// 		ft_padding(' ', pf, c_conv->nb_width - (ft_max(len, c_conv->dot_prec)));
// 	if (neg && ((nb != INT_MIN || nb != INT_MAX)))
// 		add_to_buff(pf, '-');
// 	ft_padding('0', pf, c_conv->dot_prec - len);
// 	if (c_conv->zero == 1 && c_conv->dot == 0)
// 		ft_padding('0', pf, c_conv->nb_width - (ft_max(len, c_conv->dot_prec)));