/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_majc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:00:29 by pchadeni          #+#    #+#             */
/*   Updated: 2018/05/07 11:47:39 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*display_uni(t_struct *s, wchar_t tmp)
{
	char	uni[5];
	char	*tmp_s;

	ft_bzero(uni, 5);
	tmp_s = NULL;
	if (check_chart(tmp, uni) == -1)
		return (exit_printf(s));
	if (!uni[0])
		tmp_s = ft_put_in_str(tmp_s, '\0');
	else
		tmp_s = ft_strdup(uni);
	return (tmp_s);
}

char	*conv_majc(t_struct *s, va_list ap, int *len_tmp)
{
	char	*tmp;
	wchar_t	get;

	get = va_arg(ap, wchar_t);
	tmp = NULL;
	tmp = display_uni(s, get);
	if (tmp)
		tmp = display_char(s, tmp, len_tmp);
	return (tmp);
}
