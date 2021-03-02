/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:28:39 by tnave             #+#    #+#             */
/*   Updated: 2021/03/02 23:07:58 by tnave            ###   ########.fr       */
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

t_pfconv	*ft_parse(t_pfstruct *pf, t_pfconv *c_conv, const char *str, va_list iter)
{
	if (str[pf->j] == '0')
	{
		c_conv->zero = 1;
		pf->j++;
	}
	if (str[pf->j] == '-')
	{
		c_conv->dash = 1;
		pf->j++;
	}
	ft_width(pf, c_conv, str, iter);
	while (ft_isdigit(str[pf->j]))
		pf->j++;
	ft_dot(pf, c_conv, str, iter);
	return (c_conv);
}

int		ft_printf(const char *str, ...)
{
	t_pfstruct pf;
	ft_memset(&pf, 0, sizeof(pf));
	va_list iter;
	t_pfconv c_conv;
	va_start(iter, str);

	while (str[pf.i])					
	{									
		if (str[pf.i] != '%')			  
			add_to_buff(&pf, str[pf.i]);
		if (str[pf.i] == '%')
		{
			pf.i++;
			pf.j = pf.i;
			while (!ft_type(str[pf.i]))
				pf.i++;				
			pf.type = str[pf.i];
			ft_parse(&pf, ft_reset(&c_conv), str, iter);
			ft_return_type(&pf, &c_conv, iter);
		}
		pf.i++;
	}
	empty_buff(&pf);
	va_end(iter);
	return (pf.buff_len);
}

// int main(void)
// {
	
// 	// printf("\n");
// 	// ft_printf(qw);	
// 	// printf("\n");											// width < prec
// 	// ft_printf("%s", "           abcdefghijklmnopqrstuvwxyz");	
// 	// printf("OG = %.0s", "theo");
// 	// printf("OG = %.s", "theo");							// width > prec
// 	// ft_printf("DA = %.0d", 0);
// }