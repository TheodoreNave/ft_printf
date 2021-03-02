/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:15:03 by tnave             #+#    #+#             */
/*   Updated: 2021/03/02 23:07:46 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_putnbr_base(long nb, char *base, t_pfstruct *pf)
{
	if (nb >= (long)ft_strlen(base))
	{
		ft_putnbr_base(nb / ft_strlen(base), base, pf);
		ft_putnbr_base(nb % ft_strlen(base), base, pf);
	}
	else
		add_to_buff(pf, base[nb]);
}

int				ft_atoi(char *str)
{
	long int	i;
	long int	res;
	long int	sign;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == '\v' ||
		str[i] == '\n' || str[i] == '\r' ||
		str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (sign * res);
}

void			ft_width(t_pfstruct *pf, t_pfconv *c_conv, const char *str,
				va_list iter)
{
	if (ft_isdigit(str[pf->j]) || str[pf->j] == '*')
	{
		if (str[pf->j] == '*')
		{
			c_conv->nb_width = va_arg(iter, int);
			pf->j++;
		}
		else
			c_conv->nb_width = atoi(&str[pf->j]);
	}
}

void			ft_dot(t_pfstruct *pf, t_pfconv *c_conv, const char *str,
				va_list iter)
{
	if (str[pf->j] == '.')
	{
		c_conv->dot = 1;
		c_conv->dot_prec = 0;
		pf->j++;
		if (ft_isdigit(str[pf->j]) || str[pf->j] == '*')
		{
			if (str[pf->j] == '*')
			{
				c_conv->dot_prec = va_arg(iter, int);
				pf->j++;
			}
			else
				c_conv->dot_prec = atoi(&str[pf->j]);
		}
	}
}

void			ft_return_type(t_pfstruct *pf, t_pfconv *c_conv, va_list iter)
{
	if (is_int(pf->type))
		ft_display_int(pf, *c_conv, iter);
	if (is_u_int(pf->type))
		ft_display_u_int(pf, *c_conv, iter);
	if (is_hex(pf->type))
		ft_display_hex(pf, *c_conv, iter);
	if (is_ptr(pf->type))
		ft_display_ptr(pf, *c_conv, iter);
	if (is_str(pf->type))
		ft_display_str(pf, *c_conv, iter);
	if (is_char(pf->type))
		ft_display_char(pf, *c_conv, iter);
	if (is_mod(pf->type))
		ft_display_mod(pf, *c_conv);
}
