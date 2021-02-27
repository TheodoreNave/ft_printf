/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:15:03 by tnave             #+#    #+#             */
/*   Updated: 2021/02/27 17:34:16 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_base(long nb, char *base, t_pfstruct *pf)
{
	if (nb >= (long)ft_strlen(base))
	{
		ft_putnbr_base(nb / ft_strlen(base), base, pf);
		ft_putnbr_base(nb % ft_strlen(base), base, pf);
	}
	else
		add_to_buff(pf, base[nb]);
}

// Function Shortcut here