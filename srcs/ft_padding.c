/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:22:08 by tnave             #+#    #+#             */
/*   Updated: 2021/03/08 15:40:44 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void				ft_flags(t_pfstruct *pf, t_pfconv *c_conv)
{
	if (c_conv->zero && c_conv->dash)
		c_conv->zero = 0;
	if (c_conv->dot == 1 && c_conv->dot_prec == -1)
		c_conv->dot_prec = 0;
	if (c_conv->dot == 1 && c_conv->dot_prec < -1)
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
	if (c_conv->zero && c_conv->dot && pf->type != '%')
	{
		c_conv->zero = 0;
		c_conv->dash = 0;
	}
}

int					ft_before_diux(t_pfstruct *pf, t_pfconv *c_conv,
					long nb, long i)
{
	pf->neg = 0;
	if (nb < 0)
	{
		nb = -nb;
		pf->neg = 1;
		c_conv->dot_prec++;
	}
	if (nb == 0 && c_conv->dot_prec >= 0)
		i--;
	if (pf->neg && c_conv->zero)
		add_to_buff(pf, '-');
	if (c_conv->dash != 1)
	{
		if (c_conv->zero == 1)
			ft_padding('0', pf, c_conv->nb_width - i);
		else
			ft_padding(' ', pf, c_conv->nb_width -
			(ft_max(i, c_conv->dot_prec)));
	}
	if (pf->neg && !c_conv->zero)
		add_to_buff(pf, '-');
	if (c_conv->dot)
		ft_padding('0', pf, c_conv->dot_prec - i);
	return (1);
}

int					ft_after(t_pfstruct *pf, t_pfconv *c_conv, long i)
{
	if (c_conv->dash == 1)
		ft_padding(' ', pf, c_conv->nb_width - (ft_max(i, c_conv->dot_prec)));
	pf->neg = 0;
	return (0);
}

int					ft_before_str(t_pfstruct *pf, t_pfconv *c_conv,
					char *str, int len)
{
	if (!c_conv->dash)
	{
		ft_padding(' ', pf, c_conv->nb_width - len);
		add_str_to_buff(pf, str);
	}
	else
	{
		add_str_to_buff(pf, str);
		ft_padding(' ', pf, c_conv->nb_width - len);
	}
	return (0);
}
