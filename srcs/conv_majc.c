/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_majc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:00:29 by pchadeni          #+#    #+#             */
/*   Updated: 2018/04/25 17:39:49 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	first_st(int c, char uni[4])
{
	uni[0] = c;
	return (1);
}

int	second_st(int c, char uni[4])
{
	uni[0] = (c >> 6) | 0xC0;
	uni[1] = (c & 0x3F) | 0x80;
	return (2);
}

int	third_st(int c, char uni[4])
{
	uni[0] = (c >> 12) | 0xE0;
	uni[1] = ((c >> 6) & 0x3F) | 0x80;
	uni[2] = (c & 0x3F) | 0x80;
	return (3);
}

int forth_st(int c, char uni[4])
{
	uni[0] = (c >> 16) | 0xF0;
	uni[1] = ((c >> 12) & 0x3F) | 0x80;
	uni[2] = ((c >> 6) & 0x3F) | 0x80;
	uni[3] = (c & 0x3F) | 0x80;
	return (4);
}

int	conv_majc(int c, char uni[4])
{
	if (c < 0x80)
		return (first_st(c, uni));
	if (c <= 0x7FF)
		return (second_st(c, uni));
	if (c <= 0x7FFFF)
		return (third_st(c, uni));
	if (c <= 0x7FFFFFF)
		return (forth_st(c, uni));
	return (-1);
}

char	*display_uni(t_struct *s, va_list ap, int *len_tmp)
{
	wchar_t	tmp;
	char	uni[5];
	char	*tmp_s;
	char	*res;

	ft_bzero(uni, 5);
	tmp = va_arg(ap, wchar_t);
	if (conv_majc(tmp, uni) == -1)
		exit_printf(s);
	tmp_s = ft_strdup(uni);
	res = display_char(s, tmp_s, len_tmp);
	ft_strdel(&tmp_s);
	return (display_str(s, res, len_tmp, 's'));
}