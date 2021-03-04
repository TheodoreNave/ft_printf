/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:31:31 by tnave             #+#    #+#             */
/*   Updated: 2021/03/04 19:37:03 by tnave            ###   ########.fr       */
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
	int 		i;					// Simple iterator
	int			j;					// Keep for flags
	int			x;					// Total_len
	char		type;				// Keep for type (d / s...)
	char		buff[BUFF_MAX];		// Buffer
	int			buff_len;
	int			neg;
	va_list		*iter;

}					t_pfstruct;

typedef struct		s_fllist
{
	int zero;	// 0 or not
	int dash;	// Dash or not
	int width;	// Largeur after 0 or -
	int nb_width;
	int	dot; 	// if there a dot
	int dot_prec;	// Nb prec (start at - 1)
	// int len;
}					t_pfconv;

int					ft_printf(const char *str, ...);
void				*ft_memset(void *b, int c, size_t len);
void				add_to_buff(t_pfstruct *pf, char c);
void				empty_buff(t_pfstruct *pf);
void				add_str_to_buff(t_pfstruct *pf, char *str);
int					ft_count_nbr(long nb, long base);
t_pfconv			*ft_parse(t_pfstruct *pf, t_pfconv *c_conv, const char *str);
int					ft_all_type(t_pfstruct *pf, t_pfconv c_conv);
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
int					ft_display_int(t_pfstruct *pf, t_pfconv *c_conv);
int					ft_display_u_int(t_pfstruct *pf, t_pfconv *c_conv);
int					ft_display_hex(t_pfstruct *pf, t_pfconv *c_conv);
int					ft_display_ptr(t_pfstruct *pf, t_pfconv *c_conv);
int					ft_display_str(t_pfstruct *pf, t_pfconv *c_conv);
int					ft_display_char(t_pfstruct *pf, t_pfconv *c_conv);
int					ft_display_mod(t_pfstruct *pf, t_pfconv *c_conv);
void				ft_putnbr_base(long nb, char *base, t_pfstruct *pf);
int					pf_putnbr(t_pfstruct *pf, long nb);
void				ft_padding(char c, t_pfstruct *pf, long len);
int					ft_max(long a, long b);
size_t				ft_strlen(char *str);
int					ft_atoi(const char *str, int *i);
void				ft_width(t_pfstruct *pf, t_pfconv *c_conv, const char *str);
void				ft_dot(t_pfstruct *pf, t_pfconv *c_conv, const char *str);
void 				ft_return_type(t_pfstruct *pf, t_pfconv *c_conv);
int					ft_before_diux(t_pfstruct *pf, t_pfconv *c_conv, long nb, long i);
void				ft_flags(t_pfconv *c_conv);
int					ft_after(t_pfstruct *pf, t_pfconv *c_conv, long i);

#endif


// si dash == 1 si width > 0 et si prec == 0 et si nb == 0 retourner width