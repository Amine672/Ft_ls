/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 06:32:46 by akabbouc          #+#    #+#             */
/*   Updated: 2017/01/12 06:32:47 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		conv_c(t_flags *f, t_stock *s)
{
	if (f->l == 1)
		f->flags = 'C';
	if (f->flags == 'C')
		s->wc = (wchar_t)va_arg(s->ag, int);
	else
	{
		s->s = (unsigned char)va_arg(s->ag, int);
	}
	handle_c(f, s);
}

void		handle_c(t_flags *f, t_stock *s)
{
	if (f->zero == 1 && f->preci == 1)
		f->preci = 0;
	if (f->flags != 'C')
		get_zero(f, s);
	if (f->champs <= 1 && f->preci == 1)
		f->champs = 0;
	get_signe(f, s);
	get_space(f, s);
	print_c(f, s);
}

void		conv_s(t_flags *f, t_stock *s)
{
	if (f->l == 1)
		f->flags = 'S';
	if (f->flags == 'S')
	{
		s->ws = va_arg(s->ag, wchar_t*);
		if (!s->ws)
			s->ws = L"(null)";
	}
	else
		s->sa = va_arg(s->ag, char *);
	if (!s->sa)
		s->sa = "(null)";
	handle_s(f, s);
}

void		handle_s(t_flags *f, t_stock *s)
{
	int i;

	i = 0;
	if (f->preci_len < 0)
	{
		f->champs = f->preci_len * -1;
		f->preci_len = 0;
	}
	if (f->left == 1)
		f->zero = 0;
	if (f->champs < 0)
		f->champs = 0;
	get_zero_s(f, s);
	get_space_s(f, s);
	i = (f->flags == 'S') ? ft_strnwlen(s, f) : ft_strlen(s->sa);
	print_s(f, s);
	s->lenf += i + ft_strlen(s->sp);
}

void		print_s(t_flags *f, t_stock *s)
{
	if (f->left == 1)
	{
		(f->flags == 'S') ? ft_putnwstr(s, f) : ft_putstr(s->sa);
		ft_putstr(s->sp);
	}
	if (f->zero == 0 && f->left == 0)
	{
		ft_putstr(s->sp);
		(f->flags == 'S') ? ft_putnwstr(s, f) : ft_putstr(s->sa);
	}
	if (f->zero == 1 && (f->preci == 1 || f->preci == 0))
	{
		ft_putstr(s->tmp);
		(f->flags == 'S') ? ft_putnwstr(s, f) : ft_putstr(s->sa);
	}
}
