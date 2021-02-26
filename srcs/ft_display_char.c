/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 14:35:11 by tnave             #+#    #+#             */
/*   Updated: 2021/02/24 13:27:14 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int             ft_display_char(pfstruct *type, pfconv c_conv, va_list iter)
{
        char c[2];
        int i;

        c[0] = (char)va_arg(iter, int);
        c[1] = '\0';
        i = 1;
        if (c_conv.dash)			//  check dash
	{
                add_to_buff(type, c[0]);
	        while (i < c_conv.width)
		{
			add_to_buff(type, ' ');
			i++;
		}
	} 
        else if (c_conv.width)
        {
                while (i < c_conv.width)
		{
			add_to_buff(type, ' ');
			i++;
		}
                add_to_buff(type, c[0]);
        }
        else
                add_to_buff(type, c[0]);
        return (0);
} 