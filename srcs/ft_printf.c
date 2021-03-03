/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:28:39 by tnave             #+#    #+#             */
/*   Updated: 2021/03/03 16:03:36 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// Need shortcut for parse and printf functions and each display (Normally)

int		ft_type(char c)
{
	return (c == 'c' || c == '%' || c == 'd' || c == 'u' 
	|| c == 'i' || c == 's' || c == 'x' || c == 'X' || c == 'p' || c == '\0');
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

t_pfconv	*ft_parse(t_pfstruct *pf, t_pfconv *c_conv, const char *str)
{
	while (str[pf->i] && !ft_type(str[pf->i]))
	{
		if (str[pf->i] == '0')
			c_conv->zero = 1;
		else if (str[pf->i] == '-')
			c_conv->dash = 1;
		else if (str[pf->i] == '.')
		{
			c_conv->dot = 1;
			c_conv->dot_prec = 0;
		}
		else if (ft_isdigit(str[pf->i]) && !c_conv->dot)
			c_conv->nb_width = ft_atoi(str, &pf->i);
		else if (ft_isdigit(str[pf->i]) && c_conv->dot)
			c_conv->dot_prec = ft_atoi(str, &pf->i);
		else if (str[pf->i] == '*') {
			if (!c_conv->dot)
				c_conv->nb_width = va_arg(*pf->iter, int);
			else
				c_conv->dot_prec = va_arg(*pf->iter, int);
		}
		pf->i++;
	}
	return (c_conv);
}

int		ft_printf(const char *str, ...)
{
	t_pfstruct pf;
	ft_memset(&pf, 0, sizeof(pf));
	va_list ap;
	t_pfconv c_conv;
	va_start(ap, str);

	pf.iter = &ap;
	while (str[pf.i])					
	{									
		if (str[pf.i] != '%')			  
			add_to_buff(&pf, str[pf.i]);
		if (str[pf.i] == '%')
		{
			pf.i++;
			ft_parse(&pf, ft_reset(&c_conv), str);
			if (c_conv.dot == 1 && c_conv.dot_prec < 0)
				c_conv.dot = 0;
			if (c_conv.nb_width < 0)
			{
				c_conv.dash = 1;
				c_conv.nb_width = -c_conv.nb_width;
			}
			pf.type = str[pf.i];
			ft_return_type(&pf, &c_conv);
		}
		pf.i++;
	}
	empty_buff(&pf);
	va_end(ap);
	return (pf.buff_len);
}

// int main(void)
// {
// 	printf("\n");
// 	// printf("OG = %.0s", "theo");
// 	printf("OG = %-12.6d", -42);
// 	ft_printf("DA = %-12.6d", -42);
// }