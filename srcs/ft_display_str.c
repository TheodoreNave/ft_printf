/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 14:35:01 by tnave             #+#    #+#             */
/*   Updated: 2021/02/27 14:46:38 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	is_str(char c)
{
	return (c == 's');
}

int		ft_display_str(t_pfstruct *type, t_pfconv c_conv, va_list iter)
{
    char *str;
    int i;
    int len;

    str = va_arg(iter, char *);
    i = ft_strlen(str);
	len = i;
	if (c_conv.dash == 0 && c_conv.zero == 0)
		ft_padding(' ', type, c_conv.width - (ft_max(len, c_conv.prec)));
	ft_padding(' ', type, c_conv.prec - len);
	add_str_to_buff(type, str);
	if (c_conv.dash == 1)
		ft_padding(' ', type, c_conv.width - (ft_max(len, c_conv.prec)));
	return (0);
}