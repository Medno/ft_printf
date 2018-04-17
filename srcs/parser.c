/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:21:20 by pchadeni          #+#    #+#             */
/*   Updated: 2018/04/17 19:04:04 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*check_flags(const char *format, int *i, t_struct *s)
{
	if (format[*i] && format[*i] == '#' && (*i)++)
		s->flags |= F_HASHTAG;
	if (format[*i] && format[*i] == '0' && (*i)++)
		s->flags |= F_ZERO;
	if (format[*i] && format[*i] == '-' && (*i)++)
		s->flags |= F_MINUS;
	if (format[*i] && format[*i] == ' ' && (*i)++)
		s->flags |= F_SPACE;
	if (format[*i] && format[*i] == '+' && (*i)++)
		s->flags |= F_PLUS;
	if (format[*i] && format[*i] == '\'' && (*i)++)
		s->flags |= F_QUOTE;
	return (s);
}

t_struct	*check_field(const char *format, int *i, t_struct *s, int tmp)
{
	int	field;
	int	expten;

	field = 0;
	expten = 1;
	while (format[*i] && ft_isdigit(format[*i]))
	{
		field = format[*i] - '0' + expten * field;
		expten *= 10;
		(*i)++;
	}
	if (!tmp)
		s->len_field = field;
	else
		s->precision = field;
	return (s);
}

t_struct	*check_field_prec(const char *format, int *i, t_struct *s)
{
	if (format[*i] && ft_isdigit(format[*i]))
		s = check_field(format, i, s, 0);
	if (format[*i] && format[*i] == '.')
	{
		(*i)++;
		s = check_field(format, i, s, 1);
	}
	return (s);
}

void	display_str(t_struct *s, va_list ap)
{
	char	*tmp;

	tmp = va_arg(ap, char *);
	ft_putstr(tmp);
	(void)s;
}

t_struct	*check_conversion(const char *f, int *i, t_struct *s, va_list ap)
{
	if (f[*i] == 's')
		display_str(s, ap);
	return (s);
}

void	treat_format(const char *format, int *i, t_struct *s, va_list ap)
{
	(*i)++;
	if (format[*i])
	{
		s = check_flags(format, i, s);
		s = check_field_prec(format, i, s);
		s = check_conversion(format, i, s, ap);
		(*i)++;
	}
}

void	parser(const char *format, va_list ap, t_struct *s)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_putnstr(format, i);
			s->len += i;
			treat_format(format, &i, s, ap);
			format += i;
			i = 0;
		}
		else
			i++;
	}
	ft_putnstr(format, i);
}
