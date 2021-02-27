/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_mod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:16:00 by tnave             #+#    #+#             */
/*   Updated: 2021/02/27 16:14:32 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			is_mod(char c)
{
	return (c == '%');
}

int			ft_display_mod(t_pfstruct *type, t_pfconv c_conv)
{
	char	c;
	int		i;

	c = '%';
	i = 1;
	if (c_conv.dash == 1)
	{
		add_to_buff(type, (char)c);
		ft_padding(' ', type, c_conv.width - 1);
		return (0);
	}
	if (c_conv.zero == 1)
	{
		ft_padding('0', type, c_conv.width - 1);
		add_to_buff(type, (char)c);
		return (0);
	}
	if (c_conv.width > i)
	{
		ft_padding(' ', type, c_conv.width - 1);
		add_to_buff(type, (char)c);
	}
	else
		add_to_buff(type, (char)c);
	return (i);
}
