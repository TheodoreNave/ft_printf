/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 13:39:47 by tnave             #+#    #+#             */
/*   Updated: 2021/02/27 14:46:17 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	add_to_buff(t_pfstruct *pf, char c)
{
	pf->buf[pf->x] = c;
	pf->x++;
	if (pf->x == BUFF_MAX)
		empty_buff(pf);
}

void	empty_buff(t_pfstruct *pf)
{
	write(1, &pf->buf, pf->x);
	pf->x = 0;
}

void	add_str_to_buff(t_pfstruct *pf, char *str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		add_to_buff(pf, str[i]);
		i++;
	}
}

t_pfconv	*ft_reset(t_pfconv *c_conv)
{
	c_conv->width = 0;	
	c_conv->prec = -1;	
	c_conv->dot = 0; 	 
	c_conv->conv = 0; 	
	c_conv->zero = 0;	
	c_conv->dash = 0;	
	return (c_conv);
}

int		ft_count_nbr(long nb, long base)
{
	long int	i;
	long int	nbr;

	nbr = nb;
	i = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	while (nbr >= base)
	{
		nbr = nbr / base;
		i++;
	}
	return (i + 1);
}