/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:31:31 by tnave             #+#    #+#             */
/*   Updated: 2021/02/27 17:33:53 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>


# include <stdlib.h>
# include <stdio.h>


# define BUFF_MAX 256

typedef struct		s_pflist
{
	int 	i;					// Simple iterator
	int		j;					// Keep for flags
	int		x;					// Total_len
	char 	y;					// ?
	char	stock;				// ?
	char 	*arg;				// ?
	char	type;				// Keep for type (d / s...)
	char	buf[BUFF_MAX];		// Buffer

}					t_pfstruct;

typedef struct		s_fllist
{
	int width;	// Largeur after 0 or -
	int prec;	// Nb prec (start at - 1)
	int	dot; 	// if there a dot
	int	conv; 	// type ??? Useful really ?
	int zero;	// 0 or not
	int dash;	// Dash or not

}					t_pfconv;

int					ft_printf(const char *str, ...);
void				*ft_memset(void *b, int c, size_t len);
void				add_to_buff(t_pfstruct *pf, char c);
void				empty_buff(t_pfstruct *pf);
void				add_str_to_buff(t_pfstruct *pf, char *str);
int					ft_count_nbr(long nb, long base);
t_pfconv			*ft_parse(t_pfconv *c_conv, const char *str, va_list iter);
int					ft_all_type(t_pfstruct *pf, t_pfconv c_conv, va_list iter);
t_pfconv			*ft_reset(t_pfconv *c_conv);
int					ft_type(char c);
char				is_int(char c);
char				is_u_int(char c);
char				is_hex(char c);
char				is_ptr(char c);
char				is_str(char c);
char				is_char(char c);
int					is_mod(char c);
int					ft_isdigit(int c);
int					ft_display_int(t_pfstruct *type, t_pfconv c_conv,
					va_list iter);
int					ft_display_u_int(t_pfstruct *type, t_pfconv c_conv,
					va_list iter);
int					ft_display_hex(t_pfstruct *type, t_pfconv c_conv,
					va_list iter);
int					ft_display_ptr(t_pfstruct *type, t_pfconv c_conv,
					va_list iter);
int					ft_display_str(t_pfstruct *type, t_pfconv c_conv,
					va_list iter);
int					ft_display_char(t_pfstruct *type, t_pfconv c_conv,
					va_list iter);
int					ft_display_mod(t_pfstruct *type, t_pfconv c_conv);
void				ft_putnbr_base(long nb, char *base, t_pfstruct *pf);
int					pf_putnbr(t_pfstruct *type, long nb);
void				ft_padding(char c, t_pfstruct *type, long len);
int					ft_max(long a, long b);
size_t				ft_strlen(char *str);
#endif
