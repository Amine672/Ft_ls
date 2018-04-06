/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 12:04:10 by akabbouc          #+#    #+#             */
/*   Updated: 2017/01/16 12:04:12 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_putnwchar_(t_stock *s, t_flags *f, size_t v, int size)
{
	if (size <= 16)
	{
		if ((s->wi += 3) > f->preci_len && (f->preci_len != 0 || f->preci == 1))
			return (-1);
		ft_putchar(((v >> 12) & 15) | 224);
		ft_putchar(((v >> 6) & 63) | 128);
	}
	else
	{
		if ((s->wi += 4) > f->preci_len && (f->preci_len != 0 || f->preci == 1))
			return (-1);
		ft_putchar(((v >> 18) & 7) | 240);
		ft_putchar(((v >> 12) & 63) | 128);
		ft_putchar(((v >> 6) & 63) | 128);
	}
	ft_putchar((v & 63) | 128);
	return (0);
}

size_t		ft_wcharlen(wchar_t c)
{
	unsigned int	v;
	int				size;

	v = (unsigned int)c;
	size = count_bits(c);
	if (size <= 7)
		return (1);
	else if (size <= 11)
		return (2);
	else if (size <= 16)
		return (3);
	else
		return (4);
}

size_t		ft_wstrlen(wchar_t *c)
{
	int		size;

	size = 0;
	while (c && *c)
		size += ft_wcharlen(*c++);
	return (size);
}

void		ft_putwchar(wchar_t c)
{
	size_t			v;
	int				size;

	v = (unsigned int)c;
	size = count_bits(c);
	if (size <= 7)
		return (ft_putchar(c));
	else if (size <= 11)
		ft_putchar(((v >> 6) & 31) | 192);
	else if (size <= 16)
	{
		ft_putchar(((v >> 12) & 15) | 224);
		ft_putchar(((v >> 6) & 63) | 128);
	}
	else
	{
		ft_putchar(((v >> 18) & 7) | 240);
		ft_putchar(((v >> 12) & 63) | 128);
		ft_putchar(((v >> 6) & 63) | 128);
	}
	ft_putchar((v & 63) | 128);
}

int			ft_putnwchar(t_stock *s, t_flags *f)
{
	unsigned int	v;
	int				size;

	v = (unsigned int)*s->ws;
	size = count_bits(*s->ws);
	if (size <= 7)
	{
		if (++s->wi > f->preci_len && (f->preci_len != 0 || f->preci == 1))
			return (-1);
		ft_putchar(*s->ws);
		return (0);
	}
	else if (size <= 11)
	{
		if ((s->wi += 2) > f->preci_len && (f->preci_len != 0 || f->preci == 1))
			return (-1);
		ft_putchar(((v >> 6) & 31) | 192);
		ft_putchar((v & 63) | 128);
	}
	else
		ft_putnwchar_(s, f, v, size);
	return (0);
}
