/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:21:20 by pchadeni          #+#    #+#             */
/*   Updated: 2018/04/18 16:10:30 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		digit_conv(char c)
{
	if (ft_strchr("diouxX", c))
		return (1);
	return (0);
}

t_struct	*check_conversion(const char *f, int *i, t_struct *s, va_list ap)
{
	if (f[*i] == 's')
		display_str(s, ap);
	//if (digit_conv(f[*i]))
	return (s);
}

int		is_flag(char c)
{
	if (ft_strchr("#0- +.hljz", c))
		return (1);
	return (0);
}

int		is_convert(char c)
{
	if (ft_strchr("sSpdDioOuUxXcC", c))
		return (1);
	return (0);
}

void	treat_format(const char *format, int *i, t_struct *s, va_list ap)
{
	(*i)++;
	while (format[*i] && (is_flag(format[*i]) || ft_isdigit(format[*i])))
	{
		s = check_flags(format, i, s);
		s = field_preci(format, i, s);
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
	s->str = ft_strjoindel(s->str, buf);
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
//			ft_putnstr(format, i);
			s->len += i;
			treat_format(format, &i, s, ap);
			format += i;
			i = 0;
		}
		else
			i++;
	}
	s->str = ft_strjoindel(s->str, (char *)format);
	s->len += i;
}
