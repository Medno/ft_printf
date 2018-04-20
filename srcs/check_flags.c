/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 10:33:59 by pchadeni          #+#    #+#             */
/*   Updated: 2018/04/20 15:57:25 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct		*check_flags(const char *format, int *i, t_struct *s)
{
	if (format[*i] == '#')
		s->flags |= F_HASHTAG;
	else if (format[*i] == '0' && (*i)++)
		s->flags |= F_ZERO;
	else if (format[*i] == '-')
		s->flags |= F_MINUS;
	else if (format[*i] == ' ')
		s->flags |= F_SPACE;
	else if (format[*i] == '+')
		s->flags |= F_PLUS;
//	if (format[*i] && format[*i] == '\'' && (*i)++)
//	s->flags |= F_QUOTE;
		return (s);
}

static t_struct	*check_field(const char *format, int *i, t_struct *s, int tmp)
{
	int	field;
	int	expten;

	field = 0;
	expten = 1;
	while (format[*i] && ft_isdigit(format[*i]))
	{
printf("[%c]\n", format[*i]);
		field = format[*i] - '0' + expten * field;
		expten *= 10;
		(*i)++;
	}
	if (!tmp)
		s->len_field = field;
	else
		s->precision = field;
	(*i)--;
	return (s);
}

t_struct		*check_lenmod(const char *f, int *i, t_struct *s)
{
	if (f[*i] && f[*i] == 'h' && s->modif < F_H)
		s->modif = (f[*i + 1] && f[*i + 1] == 'h' && (*i)++) ? F_HH : F_H;
	if (f[*i] && f[*i] == 'l' && s->modif < F_LL)
		s->modif = (f[*i + 1] && f[*i + 1] == 'l' && (*i)++) ? F_LL : F_L;
	if (f[*i] && f[*i] == 'j' && s->modif < F_J)
		s->modif = F_J;
	if (f[*i] && f[*i] == 'z' && s->modif < F_J)
		s->modif = F_Z;
	return (s);
}

t_struct		*field_preci(const char *format, int *i, t_struct *s)
{
	if (format[*i] && ft_isdigit(format[*i]))
		s = check_field(format, i, s, 0);
	if (format[*i] && format[*i] == '.')
	{
		(*i)++;
		s = check_field(format, i, s, 1);
	}
	if (format[*i] && ft_strchr("hljz", format[*i]))
		s = check_lenmod(format, i, s);
	return (s);
}
