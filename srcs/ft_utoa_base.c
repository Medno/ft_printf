/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:42:01 by exam              #+#    #+#             */
/*   Updated: 2018/04/19 12:06:19 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		nb_char_u(uintmax_t n, int base)
{
	int	compt;

	compt = 0;
	while (n != 0)
	{
		compt++;
		n /= base;
	}
	return (compt);
}

char	*ft_utoa_base(uintmax_t value, int base)
{
	int		nb_c;
	char	*res;
	char	labase[] = "0123456789ABCDEF";

	nb_c = nb_char_u(value, base);
	if (value == 0)
		return ("0");
	if (!(res = (char *)malloc(sizeof(char) * nb_c + 1)))
		return (NULL);
	res[nb_c] = '\0';
	nb_c--;
	while (value != 0)
	{
		res[nb_c] = labase[value % base];
		value /= base;
		nb_c--;
	}
	return (res);
}
