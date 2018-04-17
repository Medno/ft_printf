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

void	treat_format(const char *format, int *i, t_struct *s, va_list ap)
{
	(*i)++;
	while (format[*i])
	{
		(void)s;
		(void)ap;
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
			treat_format(format, &i, s, ap);
			s->len += i;
			format += i;
			i = 0;
		}
		else
			i++;
	}
}
