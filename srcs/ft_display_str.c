/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:46:20 by tnave             #+#    #+#             */
/*   Updated: 2021/03/04 19:59:08 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	is_str(char c)
{
	return (c == 's');
}

int		ft_display_str(t_pfstruct *pf, t_pfconv *c_conv)
{
    char *str;
    int i;
    int len;
	int j;
	int k;

    str = va_arg(*pf->iter, char *);
	
	if (!str)
		str = "(null)";
	if (str[0] == '\0' || str[0] == 0)
	{
		ft_padding(' ', pf, c_conv->nb_width);
		return (0);
	}
    i = ft_strlen(str);
	len = i;
	j = c_conv->dot_prec;
	k = 0;

	if (c_conv->dot == 1 && c_conv->dot_prec >= 0 && c_conv->dot_prec < len)
		len = c_conv->dot_prec;

	if (c_conv->dot == 1 && c_conv->dot_prec < 0 && c_conv->nb_width < 0)
		c_conv->dot = 0;
	if (c_conv->zero == 0 && c_conv->dash == 0 && c_conv->nb_width <= 0 && c_conv->dot == 0 && c_conv->dot_prec == -1)
	{
		add_str_to_buff(pf, str);
		return (0);
	}
	if (c_conv->dash == 0 && c_conv->nb_width <= 0 && c_conv->dot == 1 && c_conv->dot_prec == -1)
		return (0);	
	if (c_conv->dash == 0 && c_conv->nb_width > 0 && c_conv->dot == 0 && c_conv->dot_prec == -1)		// IMPORTANT
	{
		ft_padding(' ', pf, c_conv->nb_width - len);
		add_str_to_buff(pf, str);
		return (0);
	}
	if (c_conv->dash == 0 && c_conv->nb_width < 0 && c_conv->dot == 0 && c_conv->dot_prec == -1)		// IMPORTANT working on this one
	{
		ft_padding(' ', pf, c_conv->nb_width - len);
		add_str_to_buff(pf, str);
		return (0);
	}
	if (c_conv->dash == 0 && c_conv->nb_width > 0 && c_conv->dot == 1 && c_conv->dot_prec == -1)		// IMPORTANT
	{
		ft_padding(' ', pf, c_conv->nb_width);
		return (0);
	}
	if (c_conv->dash == 0 && c_conv->nb_width > 0 && c_conv->dot == 1 && c_conv->dot_prec == 0)
	{
		ft_padding(' ', pf, c_conv->nb_width - len + j);
		return (0);
	}
	if (c_conv->dash == 1 && c_conv->nb_width > 0 && c_conv->dot == 0 && c_conv->dot_prec == -1)
	{
		add_str_to_buff(pf, str);
		ft_padding(' ', pf, c_conv->nb_width - len);
		return (0);
	}
	if (c_conv->dash == 1 && c_conv->nb_width > 0 && c_conv->dot == 0)
	{
		add_str_to_buff(pf, str);
		ft_padding(' ', pf, c_conv->nb_width - len + i);
		return (0);
	}
	if (c_conv->dash == 0 && c_conv->dot_prec >= 0 && c_conv->dot_prec > len)
	{
		ft_padding(' ', pf, c_conv->nb_width - len);
		while (k < j)
		{
			add_to_buff(pf, str[k]);
			k++;
			if (k >= len)
				return (0);
		}
		return (0);
	}
	
	if (c_conv->dash == 0 && c_conv->dot_prec >= 0)
	{
		ft_padding(' ', pf, c_conv->nb_width - j);
		while (k < j)
		{
			add_to_buff(pf, str[k]);
			k++;
			if (k >= len)
				return (0);
		}
		return (0);
	}
	if (c_conv->dash == 1 && c_conv->dot_prec >= 0 && i >= j)
	{
		while (k < j && j <= len)
		{
			add_to_buff(pf, str[k]);
			k++;
		}
		ft_padding(' ', pf, c_conv->nb_width - j);
	} else {
		add_str_to_buff(pf, str);
		ft_padding(' ', pf, c_conv->nb_width - len);
	}
	return (c_conv->nb_width);
}