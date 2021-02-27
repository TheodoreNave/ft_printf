/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:28:39 by tnave             #+#    #+#             */
/*   Updated: 2021/02/27 17:34:11 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

t_pfconv	*ft_parse(t_pfconv *c_conv, const char *str, va_list iter)
{
	int i;
	
	i = 0;
	if (str[i] == '0')
	{
		c_conv->zero = 1;
		i++;
	}
	if (str[i] == '-')
	{
		c_conv->dash = 1;
		i++;
	}
	if (ft_isdigit(str[i]) || str[i] == '*')
	{
		if (str[i] == '*')
		{
			c_conv->width = va_arg(iter, int);
			i++;
		}
		else
			c_conv->width = atoi(&str[i]);				// ADD FT_ATOI
	}
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
	{
		c_conv->dot = 1;
		i++;
		if (ft_isdigit(str[i]) || str[i] == '*')
		{
			if (str[i] == '*')
			{
				c_conv->prec = va_arg(iter, int);
				i++;
			}
			else 
				c_conv->prec = atoi(&str[i]);			// ADD FT_ATOI
		}
	}
	return (c_conv);
}

int		ft_printf(const char *str, ...)
{
	t_pfstruct pf;
	ft_memset(&pf, 0, sizeof(pf));
	va_list iter;
	t_pfconv c_conv;
	va_start(iter, str);

	if (!str)
		return (0);
	while (str[pf.i])					
	{									
		if (str[pf.i] != '%')			  
			add_to_buff(&pf, str[pf.i]);
		if (str[pf.i] == '%')
		{
			pf.i++;
			if (!ft_type(str[pf.i]))
				pf.j = pf.i;
			while (!ft_type(str[pf.i]))
				pf.i++;				
			pf.type = str[pf.i];
			ft_parse(ft_reset(&c_conv), &str[pf.j], iter);
			if (is_int(pf.type))
				ft_display_int(&pf, c_conv, iter);
			if (is_u_int(pf.type))
				ft_display_u_int(&pf, c_conv, iter);
			if (is_hex(pf.type))
				ft_display_hex(&pf, c_conv, iter);
			if (is_ptr(pf.type))
				ft_display_ptr(&pf, c_conv, iter);
			if (is_str(pf.type))
				ft_display_str(&pf, c_conv, iter);
			if (is_char(pf.type))
				ft_display_char(&pf, c_conv, iter);
			if (is_mod(pf.type))
				ft_display_mod(&pf, c_conv);
		}
		pf.i++;
	}
	empty_buff(&pf);
	va_end(iter);
	return (0);												
}

int main(void)
{
	
	printf("\n");
	printf("OG PRINTF = %03x", 0);							// width > prec
	printf("\n");											// width < prec
	ft_printf("DA PRINTF = %03x", 0);
}
// // 														// If width is - cancel the prec
														// If there is a number just after the %, check directly the flag
// // // 	// printf("[%d]\n", c_conv.width);
// // // 	// printf("[%d]\n", c_conv.dot);
// // // 	// printf("[%d]\n", c_conv.prec);
// // // 	// printf("[%d]\n", c_conv.dash);
// // // 	// printf("\n");
// // // 	// printf("======MON_PRINTF_PTR=====\n");
// // // 	// ft_printf("%p", &p);
// // // 	// printf("\n");
// // // 	// printf("======OG_PRINTF_PTR=====\n");
// // //  	// printf("%p", &p);
// // //  	// printf("\n");

	 
// // // 	// printf("======MON_PRINTF_CHAR=====\n");
// // // 	// ft_printf("%c", c);
// // // 	// printf("\n");
// // // 	// printf("======OG_PRINTF_CHAR=====\n");
// // //  	// printf("%c", c);
// // //  	// printf("\n");


// // // 	// printf("======MON_PRINTF_INT_D=====\n");
// // // 	// ft_printf("%d", d);
// // // 	// printf("\n");
// // // 	// printf("======OG_PRINTF_INT_D=====\n");
// // //  	// printf("%d", d);
// // //  	// printf("\n");

	 
// // // 	// printf("======MON_PRINTF_INT_I=====\n");
// // // 	// ft_printf("%i", d);
// // // 	// printf("\n");
// // // 	// printf("======OG_PRINTF_INT_I=====\n");
// // //  	// printf("%i", d);
// // //  	// printf("\n");

	 
// // // 	// printf("======MON_PRINTF_U_INT=====\n");					// NOT WORKING
// // // 	// ft_printf("%u", d);
// // // 	// printf("\n");
// // // 	// printf("======OG_PRINTF_U_INT=====\n");
// // //  	// printf("%u", d);
// // //  	// printf("\n");

	 
// // // 	// printf("======MON_PRINTF_HEX=====\n");						// NOT WORKING
// // // 	// ft_printf("%x", d);
// // // 	// printf("\n");
// // // 	// printf("======OG_PRINTF_HEX=====\n");
// // //  	// printf("%x", d);
// // //  	// printf("\n");

	 
// // // 	// printf("======MON_PRINTF_HEX_MAJ=====\n");					// NOT WORKING
// // // 	// ft_printf("%X", d);
// // // 	// printf("\n");
// // // 	// printf("======OG_PRINTF_HEX_MAJ=====\n");
// // //  	// printf("%X", d);
// // //  	// printf("\n");
// }




// // /* ========================================================
// // Fu****g flags

// // */

// // /* ========================================================
// // Ptr still an Error with adresses 

// // */

// // /* ========================================================
// // J'avance jusqu'au % sinon j'ecris la string du printf

// // */