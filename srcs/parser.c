/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:21:20 by pchadeni          #+#    #+#             */
/*   Updated: 2018/04/20 14:20:38 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*check_conversion(const char *f, int *i, t_struct *s, va_list ap)
{
	char	*tmp;

	if (f[*i] == 's')
		tmp = display_str(s, ap);
	if (digit_conv(f[*i]))
		tmp = display_digit(s, ap, f[*i]);
	if (f[*i] == 'c')
		tmp = display_char(s, ap);
	s->str = ft_strjoindel(s->str, tmp);
	s->len += ft_strlen(tmp);
	ft_strdel(&tmp);
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
		s = check_conversion(format, i, s, ap);
	else if (format[*i])
		s = NULL;
	(*i)++;
}

void	put_in_struct(const char *f, int i, t_struct *s)
{
	char buf[i + 1];

	ft_bzero(buf, i + 1);
	ft_strncat(buf, f, i);
	s->str = ft_strjoinzero(s->str, buf, s->len);
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
	s->str = ft_strjoinzero(s->str, (char *)format, s->len);
	s->len += i;
}
