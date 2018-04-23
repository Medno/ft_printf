/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:21:20 by pchadeni          #+#    #+#             */
/*   Updated: 2018/04/23 17:37:57 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*check_conversion(const char *f, int *i, t_struct *s, va_list ap)
{
	char	*tmp;
	int		c;
	int		len_tmp;

	len_tmp = 0;
	if (f[*i] == 's' || f[*i] == 'S')
		tmp = display_str(s, ap, &len_tmp);
	if (digit_conv(f[*i]))
		tmp = display_digit(s, ap, f[*i], &len_tmp);
	if (f[*i] == '%')
		tmp = display_char(s, '%', &len_tmp);
	if (f[*i] == 'p')
		tmp = conv_p(s, ap, &len_tmp);
	if (f[*i] == 'c' || f[*i] == 'C')
	{
		c = va_arg(ap, int);
		tmp = display_char(s, c, &len_tmp);
	}
	if (tmp)
	{
		s->str = ft_strjoinzero(s->str, tmp, s->len, len_tmp);
		s->len += len_tmp;
		ft_strdel(&tmp);
	}
	return (s);
}

void	treat_format(const char *format, int *i, t_struct *s, va_list ap)
{
	(*i)++;
	while (format[*i] && (is_flag(format[*i]) || ft_isdigit(format[*i])))
	{
		s = check_flags(format, i, s);
		s = (format[*i]) ? field_preci(format, i, s) : s;
		(*i)++;
	}
	if (format[*i] && is_convert(format[*i]))
	{
		s->modif = (ft_strchr("DUO", format[*i])) ? F_L : s->modif;
		s = check_conversion(format, i, s, ap);
	}
	(*i)++;
}

void	put_in_struct(const char *f, int i, t_struct *s)
{
	char buf[i + 1];

	ft_bzero(buf, i + 1);
	ft_strncat(buf, f, i);
	s->str = ft_strjoinzero(s->str, buf, s->len, i);
}

void	parser(const char *format, va_list ap, t_struct *s)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			put_in_struct(format, i, s);
			s->len += i;
			treat_format(format, &i, s, ap);
			format += i;
			i = 0;
		}
		else
			i++;
	}
	s->str = ft_strjoinzero(s->str, (char *)format, s->len, i);
	s->len += i;
}
