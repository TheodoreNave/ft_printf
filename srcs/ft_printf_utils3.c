/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:15:03 by tnave             #+#    #+#             */
/*   Updated: 2021/03/10 10:54:30 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_putnbr_base(long nb, char *base, t_pfstruct *pf)
{
	if (nb == LONG_MAX)
	{
		add_str_to_buff(pf, "7fffffffffffffff");
		return ;
	}
	if (nb == LONG_MIN)
	{
		add_str_to_buff(pf, "8000000000000000");
		return ;
	}
	if ((unsigned long)nb == ULONG_MAX)
	{
		add_str_to_buff(pf, "ffffffffffffffff");
		return ;
	}
	if (nb >= (long)ft_strlen(base))
	{
		ft_putnbr_base(nb / ft_strlen(base), base, pf);
		ft_putnbr_base(nb % ft_strlen(base), base, pf);
	}
	else
		add_to_buff(pf, base[nb]);
}

int				ft_atoi(const char *str, int *i)
{
	long int	res;

	res = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		res = res * 10 + str[*i] - '0';
		(*i)++;
	}
	(*i)--;
	return (res);
}

void			ft_return_type(t_pfstruct *pf, t_pfconv *c_conv)
{
	if (is_int(pf->type))
		ft_display_int(pf, c_conv);
	if (is_u_int(pf->type))
		ft_display_u_int(pf, c_conv);
	if (is_hex(pf->type))
		ft_display_hex(pf, c_conv);
	if (is_ptr(pf->type))
		ft_display_ptr(pf, c_conv);
	if (is_str(pf->type))
		ft_display_str(pf, c_conv);
	if (is_char(pf->type))
		ft_display_char(pf, c_conv);
	if (is_mod(pf->type))
		ft_display_mod(pf, c_conv);
}

int				print_begin(t_pfstruct *pf,
				t_pfconv *c_co, uintptr_t nb, int len)
{
	if (pf->type == 'p' && c_co->dot && c_co->dash)
		c_co->ox = 1;
	if (pf->type == 'p' && c_co->dot && c_co->dash && c_co->ox && nb == 0)
	{
		add_str_to_buff(pf, "0x");
		ft_padding(' ', pf, c_co->nb_width - len + 1);
		return (0);
	}
	if (nb == 0 && c_co->dot_prec == 0)
	{
		ft_padding(' ', pf, c_co->nb_width - (ft_max(--len, c_co->dot_prec)));
		add_str_to_buff(pf, "0x");
		return (0);
	}
	if (c_co->dash == 0 && c_co->zero == 0)
		ft_padding(' ', pf, c_co->nb_width - (ft_max(len, c_co->dot_prec)));
	ft_padding('0', pf, c_co->dot_prec - len);
	return (1);
}
