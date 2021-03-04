/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:15:03 by tnave             #+#    #+#             */
/*   Updated: 2021/03/04 12:57:44 by tnave            ###   ########.fr       */
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



	// if (c_conv->dot == 1 && c_conv->dot_prec >= 0)
	// {
	// 	// Became ' ' and not 0;
	// }



// void			ft_width(t_pfstruct *pf, t_pfconv *c_conv, const char *str)
// {
// 	if (ft_isdigit(str[pf->i]) || str[pf->i] == '*')
// 	{
// 		if (str[pf->i] == '*')
// 		{
// 			c_conv->nb_width = va_arg(*pf->iter, int);
// 			pf->i++;
// 		}
// 		else
// 			c_conv->nb_width = ft_atoi(str, &pf->i);
// 	}
// }

// void			ft_dot(t_pfstruct *pf, t_pfconv *c_conv, const char *str)
// {
// 	if (str[pf->i] == '.')
// 	{
// 		c_conv->dot = 1;
// 		c_conv->dot_prec = 0;
// 		pf->i++;
// 		if (ft_isdigit(str[pf->i]) || str[pf->i] == '*')
// 		{
// 			if (str[pf->i] == '*')
// 			{
// 				c_conv->dot_prec = va_arg(*pf->iter, int);
// 				pf->i++;
// 			}
// 			else
// 				c_conv->dot_prec = ft_atoi(str, &pf->i);
// 		}
// 	}
// }
