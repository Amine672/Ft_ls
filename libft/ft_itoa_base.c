/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 03:15:22 by akabbouc          #+#    #+#             */
/*   Updated: 2017/01/11 03:15:24 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_tkt(char c)
{
	char		*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	return (base);
}

char		*ft_itoa_base(long int n, int i, char c)
{
	int			len;
	long int	nb_tmp;
	char		*str;
	char		*base;

	base = ft_tkt(c);
	if (!n)
		return (ft_strdup("0"));
	len = 0;
	nb_tmp = n;
	while (++len && nb_tmp)
		nb_tmp /= i;
	if (!(str = (char*)malloc(sizeof(char) * (len))))
		return (NULL);
	str[--len] = '\0';
	*str = '0';
	while (n != 0)
	{
		if ((n % i) > 9)
			str[--len] = base[n % i];
		else
			str[--len] = '0' + (n % i);
		n /= i;
	}
	return (str);
}
