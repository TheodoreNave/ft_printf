/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 14:35:01 by tnave             #+#    #+#             */
/*   Updated: 2021/03/02 12:16:54 by tnave            ###   ########.fr       */
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
	
	if (!str)
		str = "(null)";
	if (str[0] == '\0' || str[0] == 0)
	{
		ft_padding(' ', type, c_conv.width);
		return (0);
	}
    i = ft_strlen(str);
	len = i;
	// printf("%d\n", len);
	j = c_conv.prec;
	k = 0;
	// printf("\n");
	// printf("len of i = %d\n", i);
	// printf("dot = %d\n", c_conv.dot);
	// printf("zero = %d\n", c_conv.zero);
	// printf("dash = %d\n", c_conv.dash);
	// printf("width = %d\n", c_conv.width);
	// printf("prec = %d\n", c_conv.prec);

	// if (c_conv.dash == 0 && c_conv.prec == -1)
	// {
	// 	ft_padding(' ', type, c_conv.width - i);
	// 	add_str_to_buff(type, str);
	// 	return (0);
	// }

	// MISSING NORMAL STRING && STRING EMPTY && ADD STUFF AT THE END OF THE STRING && REVERSE PRINTF WHEN NO DASH

	// printf("salut\n");

	if (c_conv.dot == 1 && c_conv.prec >= 0 && c_conv.prec < len)
		len = c_conv.prec;

	if (c_conv.dot == 1 && c_conv.prec < 0)
		c_conv.dot = 0;

	if (c_conv.zero == 0 && c_conv.dash == 0 && c_conv.width <= 0 && c_conv.dot == 0 && c_conv.prec == -1)
	{
		// printf("up");
		add_str_to_buff(type, str);
		return (0);
	}
	if (c_conv.dash == 0 && c_conv.width <= 0 && c_conv.dot == 1 && c_conv.prec == -1)
	{
		return (0);	
	}
	if (c_conv.dash == 0 && c_conv.width > 0 && c_conv.dot == 0 && c_conv.prec == -1)		// IMPORTANT
	{
		// printf("up");
		ft_padding(' ', type, c_conv.width - len);
		add_str_to_buff(type, str);
		return (0);
	}
	if (c_conv.dash == 0 && c_conv.width > 0 && c_conv.dot == 1 && c_conv.prec == -1)		// IMPORTANT
	{
		// printf("up");
		ft_padding(' ', type, c_conv.width);
		return (0);
	}
	if (c_conv.dash == 0 && c_conv.width > 0 && c_conv.dot == 1 && c_conv.prec == 0)
	{
		// printf("up");
		ft_padding(' ', type, c_conv.width - len + j);
		return (0);
	}
	if (c_conv.dash == 1 && c_conv.width > 0 && c_conv.dot == 0 && c_conv.prec == -1)
	{
		// printf("up");
		add_str_to_buff(type, str);
		ft_padding(' ', type, c_conv.width - len);
		return (0);
	}
	
	// if (c_conv.dash == 0 && c_conv.width > 0 && c_conv.prec == -1)
	// {
	// 	ft_padding(' ', type, c_conv.width - len + i);
	// 	add_str_to_buff(type, str);
	// 	return (0);
	// }
	if (c_conv.dash == 1 && c_conv.width > 0 && c_conv.dot == 0)
	{
		// printf("up");
		add_str_to_buff(type, str);
		ft_padding(' ', type, c_conv.width - len + i);
		return (0);
	}
	// if (c_conv.width > 0)
	// {
	// 	ft_padding(' ', type, c_conv.width - j);
		
	// }
	// if (c_conv.dash == 0 && c_conv.prec < c_conv.width)
	// {
	// 	ft_padding(' ', type, c_conv.width - len);				// was j before
	// 	while (k < j)
	// 	{
	// 		add_to_buff(type, str[k]);
	// 		k++;
	// 		if (k >= len)
	// 			return (0);
	// 	}
	// 	return (0);
	// }
	if (c_conv.dash == 0 && c_conv.prec >= 0 && c_conv.prec > len)					// YOLO
	{
		// printf("up");
		ft_padding(' ', type, c_conv.width - len);				// was j before then len
		while (k < j)
		{
			add_to_buff(type, str[k]);
			k++;
			if (k >= len)
				return (0);
		}
		return (0);
	}
	
	if (c_conv.dash == 0 && c_conv.prec >= 0)
	{
		// printf("up");
		ft_padding(' ', type, c_conv.width - j);				// was j before then len
		while (k < j)
		{
			add_to_buff(type, str[k]);
			k++;
			if (k >= len)
				return (0);
		}
		return (0);
	}
	if (c_conv.dash == 1 && c_conv.prec >= 0 && i >= j)
	{
		// printf("up");
		while (k < j && j <= len)
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