/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_short.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 21:17:36 by akabbouc          #+#    #+#             */
/*   Updated: 2017/01/10 21:17:39 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_itoaneg(char *str, short tmp, short len)
{
	short		l;

	l = len - 1;
	tmp = -tmp;
	while (tmp)
	{
		str[--len] = '0' + (tmp % 10);
		tmp /= 10;
	}
	*str = '-';
	return (str);
}

char			*ft_itoa_short(short n)
{
	short		len;
	short		tmp;
	char		*str;

	tmp = n;
	len = ((n <= 0) ? 1 : 0);
	while (++len && tmp)
		tmp /= 10;
	if (!(str = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	tmp = n;
	str[--len] = '\0';
	*str = '0';
	if (tmp >= 0)
		while (tmp)
		{
			str[--len] = '0' + (tmp % 10);
			tmp /= 10;
		}
	else
		return (ft_itoaneg(str, tmp, len));
	return (str);
}
