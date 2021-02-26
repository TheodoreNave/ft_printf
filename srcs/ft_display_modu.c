/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_modu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 14:24:28 by tnave             #+#    #+#             */
/*   Updated: 2021/02/26 15:45:56 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_display_modu(pfstruct *type, pfconv c_conv)
{
	char c;
	int i;

	c = '%';
	i = 1;
	if (c_conv.dash == 1)
    {
        add_to_buff(type, (char)c);
		padding(' ', type, c_conv.width - 1);
        return (0);
	}
	if (c_conv.zero == 1)
	{
		padding('0', type, c_conv.width - 1);
		add_to_buff(type, (char)c);
		return (0);
	}
	if (c_conv.width > i)
	{
        padding(' ', type, c_conv.width - 1);
        add_to_buff(type, (char)c);	
    }
	else
        add_to_buff(type, (char)c);
	return (i);
}