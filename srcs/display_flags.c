/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:11:31 by pchadeni          #+#    #+#             */
/*   Updated: 2018/04/19 15:54:54 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	display_flag(t_struct *s, char *str, char conv, int pos)
{
	char	*tmp;
	char	buf[4];

	ft_bzero(buf, 4);
	if (s->flags & F_HASHTAG && conv == 'o' && str[0] != '0')
		buf = ft_strcat(buf, "0");
	if (s->flags & F_HASHTAG && (conv == 'x' || conv == 'X'))
	{
		buf = (conv == 'x') ? ft_strcat(buf, "0x") :
			ft_strcat(buf, "0X");
	}
	buf = (s->flags & F_PLUS && pos) ? ft_strcat(buf, "+") : buf;
	buf = (!pos) ? ft_strcat(buf, "-") : buf;
	if (!(s->flags & F_PLUS) && !(s->flags & F_MINUS) && (s->flags & F_SPACE)
			&& pos)
		buf = ft_strcat(buf, " ");
	tmp = ft_strjoindel(tmp, str);
}

char	*display_field(char *t, int len_tmp, char to_print)
{
	char	buf[len_tmp + 1];
	int		i;
	char	*tmp;

	i = 0;
	while (i < len_tmp)
	{
		buf[i] = to_print;
		i++;
	}
	buf[i] = '\0';
	tmp = ft_strdup(buf);
	return (tmp);
}

char	*display_sp(t_struct *s, char *t, int len_tmp)
{
	int		len;
	char	to_print;
	int		res_prec;
	char	*tmp;

	to_print = ' ';
	if ((s->flags & F_ZERO) && !(s->flags & F_MINUS))
		to_print = '0';
	len = (s->precision == -1) ? len_tmp : s->precision;
	tmp = NULL;
	if (len < s->len_field)
		tmp = display_field(tmp, s->len_field - len, to_print);
	return (tmp);
}

char	*check_precision(t_struct *s, char *tmp)
{
	char	*res
	int		len;

	len = ft_strlen(tmp);
	if (s->precision != -1 && s->precision <= len)
	{
		res = ft_strndup(tmp, s->precision);
		ft_strdel(&tmp);
		return (res);
	}
	else
		return (tmp);
}
