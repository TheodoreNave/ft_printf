/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:22:08 by tnave             #+#    #+#             */
/*   Updated: 2021/03/04 19:55:45 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_flags(t_pfconv *c_conv)
{
	if (c_conv->dot == 1 && c_conv->dot_prec < 0)
	{
		c_conv->dot = 0;
		c_conv->dot_prec = -1;
	}
	if (c_conv->nb_width < 0)
	{
		c_conv->dash = 1;
		c_conv->zero = 0;
		c_conv->nb_width = -c_conv->nb_width;
	}
}
int		ft_before_diux(t_pfstruct *pf, t_pfconv *c_conv, long nb, long i)
{
	pf->neg = 0;
	if (nb < 0)
	{
		nb = -nb;
		pf->neg = 1;
		c_conv->dot_prec++;
	}
	if (nb == 0 && c_conv->dot == 1 && c_conv->dot_prec == 0 && c_conv->nb_width == 0)
		return (0);
	if (c_conv->dash == 0 && c_conv->nb_width < 0 && c_conv->dot_prec == -1 && c_conv->dot == 1 && nb == 0)
		return (0);
	if (c_conv->nb_width > 0 && c_conv->dot == 1 && c_conv->dot_prec == 0 && nb == 0)
	{
		ft_padding(' ', pf, c_conv->nb_width);
		return (0);
	}
	if (c_conv->nb_width > 0 && c_conv->dot == 1 && c_conv->dot_prec == -1)
	{
		ft_padding(' ', pf, c_conv->nb_width);
		return (0);
	}
	if (c_conv->dot_prec > 0 && c_conv->zero == 1)
	{
		c_conv->zero = 0;
		c_conv->dash = 0;
	}
	if (c_conv->dash == 0 && c_conv->zero == 0)
		ft_padding(' ', pf, c_conv->nb_width - (ft_max(i, c_conv->dot_prec)));
	if (pf->neg && ((nb != INT_MIN || nb != INT_MAX)))
		add_to_buff(pf, '-');
	ft_padding('0', pf, c_conv->dot_prec - i);
	if (c_conv->zero == 1 && c_conv->dot == 0)
		ft_padding('0', pf, c_conv->nb_width - (ft_max(i, c_conv->dot_prec)));
	return (1);
}






































// if (neg && ((nb != INT_MIN || nb != INT_MAX)))
	// 	add_to_buff(pf, '-');
	// ft_padding('0', pf, c_conv->dot_prec - len());
	// if (c_conv->zero == 1 && c_conv->dot_prec == 0)
	// 	ft_padding('0', pf, c_conv->nb_width - (ft_max(len, c_conv->dot_prec)));
// void		ft_before_cs(t_pfstruct *pf, t_pfconv *c_conv)
// {

// }

// void		ft_before_p(t_pfstruct *pf, t_pfconv *c_conv)
// {

// }

int		ft_after(t_pfstruct *pf, t_pfconv *c_conv, long i)
{
	if (c_conv->dash == 1)
		ft_padding(' ', pf, c_conv->nb_width - (ft_max(i, c_conv->dot_prec)));
	pf->neg = 0;
	return (0);
}

// int			do_nothing(t_pfstruct *pf, t_pfconv *c_conv)
// {
	
// }