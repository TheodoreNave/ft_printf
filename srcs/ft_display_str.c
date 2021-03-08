/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:46:20 by tnave             #+#    #+#             */
/*   Updated: 2021/03/08 12:57:34 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			is_str(char c)
{
	return (c == 's');
}

int				ft_display_str(t_pfstruct *pf, t_pfconv *c_conv)
{
	char		*str;
	int			len;

	str = va_arg(*pf->iter, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (!c_conv->dot)
		return (ft_before_str(pf, c_conv, str, len));
	if (!ft_after_str_1(pf, c_conv, str, len))
		return (0);
	if (!ft_after_str_2(pf, c_conv, str, len))
		return (0);
	return (0);
}

int				ft_after_str_1(t_pfstruct *pf, t_pfconv *c_conv,
				char *str, int len)
{
	int			k;

	k = 0;
	if (!c_conv->dash && c_conv->dot_prec >= 0)
	{
		if (c_conv->dot_prec > len)
			ft_padding(' ', pf, c_conv->nb_width - len);
		else
			ft_padding(' ', pf, c_conv->nb_width - c_conv->dot_prec);
		while (k < c_conv->dot_prec && str[k])
		{
			add_to_buff(pf, str[k]);
			k++;
		}
		return (0);
	}
	return (1);
}

int				ft_after_str_2(t_pfstruct *pf, t_pfconv *c_conv,
				char *str, int len)
{
	int			k;

	k = 0;
	if (c_conv->dash && c_conv->dot_prec >= 0 && len >= c_conv->dot_prec)
	{
		while (k < c_conv->dot_prec && str[k])
		{
			add_to_buff(pf, str[k]);
			k++;
		}
		ft_padding(' ', pf, c_conv->nb_width - c_conv->dot_prec);
	}
	else
	{
		add_str_to_buff(pf, str);
		ft_padding(' ', pf, c_conv->nb_width - len);
	}
	return (1);
}
