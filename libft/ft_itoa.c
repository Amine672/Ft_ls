/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 06:03:34 by akabbouc          #+#    #+#             */
/*   Updated: 2016/11/12 02:53:44 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_itoaneg(char *str, int tmp, int len)
{
	int l;

	l = len - 1;
	if (tmp == -2147483648)
		return (ft_strdup("-2147483648"));
	tmp = -tmp;
	while (tmp)
	{
		str[--len] = '0' + (tmp % 10);
		tmp /= 10;
	}
	*str = '-';
	return (str);
}

char			*ft_itoa(int n)
{
	int		len;
	int		tmp;
	char	*str;

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
