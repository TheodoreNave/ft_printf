/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 14:35:11 by tnave             #+#    #+#             */
/*   Updated: 2021/03/06 16:31:18 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	is_char(char c)
{
	return (c == 'c');
}

int		ft_display_char(t_pfstruct *pf, t_pfconv *c_conv)
{
	int	c;
	int	i;

	c = va_arg(*pf->iter, int);
	i = 1;
	if (c_conv->dash == 1)
	{
		add_to_buff(pf, (char)c);
		ft_padding(' ', pf, c_conv->nb_width - 1);
		return (0);
	}
	if (c_conv->nb_width > i)
	{
		ft_padding(' ', pf, c_conv->nb_width - 1);
		add_to_buff(pf, (char)c);
	}
	else
	{
		add_to_buff(pf, (char)c);
	}
	return (c_conv->nb_width);
}
