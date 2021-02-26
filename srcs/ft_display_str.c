/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 14:35:01 by tnave             #+#    #+#             */
/*   Updated: 2021/02/24 13:27:23 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int             ft_display_str(pfstruct *type, pfconv c_conv, va_list iter)
{
        char *str;
        int i;
        int len;

        str = va_arg(iter, char *);
        i = ft_strlen(str);
	len = i;
	if (c_conv.dash == 0 && c_conv.zero == 0)
		padding(' ', type, c_conv.width - (max(len, c_conv.prec)));
	padding(' ', type, c_conv.prec - len);
	add_str_to_buff(type, str);
	if (c_conv.dash == 1)
		padding(' ', type, c_conv.width - (max(len, c_conv.prec)));
	return (0);
}