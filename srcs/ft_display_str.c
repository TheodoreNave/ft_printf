/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 14:35:01 by tnave             #+#    #+#             */
/*   Updated: 2021/02/28 15:12:25 by tnave            ###   ########.fr       */
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
	int j;
	int k;

    str = va_arg(iter, char *);
    i = ft_strlen(str);
	len = i;
	j = c_conv.prec;
	k = 0;
	// printf("\n");
	// printf("len of i = %d\n", i);
	// printf("dot = %d\n", c_conv.dot);
	// printf("zero = %d\n", c_conv.zero);
	// printf("dash = %d\n", c_conv.dash);
	// printf("width = %d\n", c_conv.width);
	// printf("prec = %d\n", c_conv.prec);
	if (!str || str == NULL)
		add_str_to_buff(type, "NULL");
	if (c_conv.dash == 0 && c_conv.prec == -1)
	{
		ft_padding(' ', type, c_conv.width - i);
		add_str_to_buff(type, str);
		return (0);
	}
	if (c_conv.dash == 1 && c_conv.prec == -1)
	{
		add_str_to_buff(type, str);
		ft_padding(' ', type, c_conv.width - i);
		return (0);
	}
	if (c_conv.dash == 0 && c_conv.prec >= 0)
	{
		while (k < j)
		{
			add_to_buff(type, str[k]);
			k++;
		}
		return (0);
	}
	if (c_conv.dash == 1 && c_conv.prec >= 0 && i >= j)
	{
		while (k < j)
		{
			add_to_buff(type, str[k]);
			k++;
		}
		ft_padding(' ', type, c_conv.width - j);
	} else {
		add_str_to_buff(type, str);
		ft_padding(' ', type, c_conv.width - len);
	}

	return (c_conv.width);
}