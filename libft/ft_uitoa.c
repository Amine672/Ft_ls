/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 00:57:31 by akabbouc          #+#    #+#             */
/*   Updated: 2017/01/11 00:57:34 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_uitoa(unsigned long int n)
{
	int					len;
	unsigned long int	nb_tmp;
	char				*str;

	if (!n)
		return (ft_strdup("0"));
	len = 0;
	nb_tmp = n;
	while (++len && nb_tmp)
		nb_tmp /= 10;
	if (!(str = (char*)malloc(sizeof(char) * (len))))
		return (NULL);
	str[--len] = '\0';
	*str = '0';
	nb_tmp = n;
	while (nb_tmp != 0)
	{
		str[--len] = '0' + (nb_tmp % 10);
		nb_tmp /= 10;
	}
	return (str);
}
