/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:21:20 by pchadeni          #+#    #+#             */
/*   Updated: 2018/04/19 15:40:33 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		digit_conv(char c)
{
	if (ft_strchr("dDoOuUixX", c))
		return (1);
	return (0);
}

t_struct	*check_conversion(const char *f, int *i, t_struct *s, va_list ap)
{
	char	*tmp;

	tmp = ft_strdup("");
	if (f[*i] == 's')
		tmp = display_str(s, ap, tmp);
	if (digit_conv(f[*i]))
		tmp = display_digit(s, ap, tmp, f[*i]);
	s->str = ft_strjoindel(tmp, s->str);
	s->len += ft_strlen(tmp);
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
