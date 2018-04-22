/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strzerojoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 08:56:28 by pchadeni          #+#    #+#             */
/*   Updated: 2018/01/23 11:49:14 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strzerocat(char *s1, char *s2, int len1, int len2)
{
	int	j;

	j = 0;
	while (j < len2)
	{
		s1[len1] = s2[j];
		len1++;
		j++;
	}
	s1[len1] = '\0';
	return (s1);
}

char	*ft_strjoinzero(char *s1, char *s2, int len)
{
	char	*tmp;
	int		len_tmp;

	if (s1 && s2)
	{
		len_tmp = ft_strlen(s2);
		if ((tmp = ft_strnew(len + ft_strlen(s2))))
		{
			tmp = ft_strzerocat(tmp, s1, 0, len);
			tmp = ft_strzerocat(tmp, s2, len, len_tmp);
			ft_strdel(&s1);
			return (tmp);
		}
	}
	else if (s1)
		return (s1);
	return (NULL);
}
