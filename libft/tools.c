/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 12:57:07 by akabbouc          #+#    #+#             */
/*   Updated: 2017/01/16 12:57:29 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_bits(unsigned int nbr)
{
	size_t	i;

	i = 1;
	while (nbr >>= 1)
		i++;
	return (i);
}

int		ft_cstrwlen_(t_stock *s, t_flags *f, int size)
{
	if (size <= 16)
	{
		if (s->wi + 3 > f->preci_len && (f->preci_len != 0 || f->preci == 1))
			return (-1);
		s->wi += 3;
	}
	else
	{
		if (s->wi + 4 > f->preci_len && (f->preci_len != 0 || f->preci == 1))
			return (-1);
		s->wi += 4;
	}
	return (0);
}

int		ft_cstrwlen(t_stock *s, t_flags *f)
{
	int				size;

	size = count_bits(*s->wtmp);
	if (size <= 7)
	{
		if (s->wi + 1 > f->preci_len && (f->preci_len != 0 || f->preci == 1))
			return (-1);
		s->wi++;
		return (0);
	}
	else if (size <= 11)
	{
		if (s->wi + 2 > f->preci_len && (f->preci_len != 0 || f->preci == 1))
			return (-1);
		s->wi += 2;
	}
	else if ((ft_cstrwlen_(s, f, size)) == -1)
		return (-1);
	return (0);
}

size_t	ft_strnwlen(t_stock *s, t_flags *f)
{
	s->wi = 0;
	s->wtmp = s->ws;
	while (s->wtmp && *s->wtmp)
	{
		if (ft_cstrwlen(s, f) == -1)
			return (s->wi);
		s->wtmp++;
	}
	return (s->wi);
}
