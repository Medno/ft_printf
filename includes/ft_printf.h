/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:33:42 by pchadeni          #+#    #+#             */
/*   Updated: 2018/04/18 16:11:27 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

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
	int		len_modif;
	int		len;
}				t_struct;

int				ft_printf(const char *format, ...);
void			parser(const char *f, va_list va, t_struct *s);
t_struct		*field_preci(const char *format, int *i, t_struct *s);
t_struct		*check_flags(const char *format, int *i, t_struct *s);
void			init_struct(t_struct *s);
void			display_str(t_struct *s, va_list ap);

void			ft_putstr(const char *s);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void			ft_putnstr(const char *s, size_t len);
size_t			ft_strlen(const char *s);
int				ft_isdigit(int a);
int				ft_isalpha(int c);
char			*ft_strchr(const char *s, int c);

//todel
void	print_flag(t_struct s);
#endif
