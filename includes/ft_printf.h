/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:33:42 by pchadeni          #+#    #+#             */
/*   Updated: 2018/04/20 11:51:10 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define F_HASHTAG	1
# define F_ZERO		2
# define F_MINUS	4
# define F_SPACE	8
# define F_PLUS		16
//# define F_QUOTE	32

# define F_HH		1
# define F_H		2
# define F_L		3
# define F_LL		4
# define F_J		5
# define F_Z		6

typedef struct	s_struct
{
	int		flags;
	int		precision;
	int		len_field;
	int		modif;
	int		len;
	char	*str;
}				t_struct;

int				ft_printf(const char *format, ...);
void			parser(const char *f, va_list va, t_struct *s);
t_struct		*field_preci(const char *format, int *i, t_struct *s);
t_struct		*check_flags(const char *format, int *i, t_struct *s);
void			init_struct(t_struct *s);
char			*display_flags(t_struct *s, char *str, int pos);
char			*display_hex_oct(t_struct *s, char *str, char conv, int pos);
char			*display_str(t_struct *s, va_list ap);
char			*display_digit(t_struct *s, va_list ap, char conv);
char			*display_char(t_struct *s, va_list ap);
char			*display_sp(t_struct *s, int len_tmp);
void			put_in_struct(const char *f, int i, t_struct *s);
char			*check_precision(t_struct *s, char *tmp);

char			*ft_itoa_base(intmax_t value, int base);
char			*ft_utoa_base(uintmax_t value, int base);
char			*conv_di(t_struct *s, va_list ap, char c);
char			*conv_ouxx(t_struct *s, va_list ap, char c);
int				nb_char_u(uintmax_t n, int base);
int				nb_char(intmax_t n, int base);

int				is_convert(char c);
int				is_flag(char c);
int				digit_conv(char c);

char			*ft_strjoinzero(char *s1, char *s2, int len);
//todel
void	print_flag(t_struct s);
#endif
