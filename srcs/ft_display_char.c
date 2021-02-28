/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 14:35:11 by tnave             #+#    #+#             */
/*   Updated: 2021/02/28 13:03:57 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	is_char(char c)
{
	return (c == 'c');
}

int		ft_display_char(t_pfstruct *type, t_pfconv c_conv, va_list iter)
{
	int	c;
	int	i;

	c = va_arg(iter, int);
	i = 1;
	if (c_conv.dash == 1)
	{
		add_to_buff(type, (char)c);
		ft_padding(' ', type, c_conv.width - 1);
		return (0);
	}
	if (c_conv.width > i)
	{
		ft_padding(' ', type, c_conv.width - 1);
		add_to_buff(type, (char)c);
	} else {
		add_to_buff(type, (char)c);
	}
	return (c_conv.width);
}
