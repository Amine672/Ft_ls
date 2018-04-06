/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 03:54:55 by akabbouc          #+#    #+#             */
/*   Updated: 2017/01/11 03:54:58 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_x(t_flags *f, t_stock *s)
{
	if (f->hast == 1 && s->i == 0)
		f->hast = 0;
	if (f->hast == 1 && f->conv == 16 && f->preci == 1 && f->preci_len != 0)
		f->champs += 2;
	if (f->flags == 'x' || f->flags == 'p')
		s->si = ft_itoa_base(s->i, f->conv, 'x');
	if (f->flags == 'X')
		s->si = ft_itoa_base(s->i, f->conv, 'X');
	if (s->i < 0)
	{
		f->neg = 1;
		if (f->flags == 'x' || f->flags == 'p')
			s->si = ft_itoa_base_neg(s->i, f->conv, 'x');
		if (f->flags == 'X')
			s->si = ft_itoa_base_neg(s->i, f->conv, 'X');
	}
	if (s->i == 0 && f->preci == 1)
		s->si = "";
	f->plus = 0;
	f->blank = 0;
	if (f->left == 1 && f->zero == 1)
		f->zero = 0;
	print_d(f, s);
}

void	handle_o(t_flags *f, t_stock *s)
{
	f->plus = 0;
	f->blank = 0;
	if (f->left == 1 && f->zero == 1)
		f->zero = 0;
	print_d(f, s);
}

void	conv_x(t_flags *f, t_stock *s)
{
	if (f->flags == 'p')
		f->hast = 0;
	if (f->h == 1 && f->flags != 'p')
		s->i = (unsigned short)va_arg(s->ag, int);
	else if (f->hh == 1 && f->flags != 'p')
		s->i = (unsigned char)va_arg(s->ag, int);
	else if (f->l == 1 || f->jz == 1 || f->flags == 'p')
		s->i = va_arg(s->ag, unsigned long);
	else if (f->ll == 1)
		s->i = va_arg(s->ag, unsigned long long);
	else
		s->i = va_arg(s->ag, unsigned int);
	handle_x(f, s);
}

void	conv_o(t_flags *f, t_stock *s)
{
	if (f->h == 1 && f->flags != 'O')
		s->i = (unsigned short)va_arg(s->ag, int);
	else if (f->hh == 1 && f->flags != 'O')
		s->i = (unsigned char)va_arg(s->ag, int);
	else if (f->l == 1 || f->flags == 'O' || f->jz == 1)
		s->i = va_arg(s->ag, unsigned long);
	else if (f->ll == 1)
		s->i = va_arg(s->ag, unsigned long long);
	else
		s->i = va_arg(s->ag, unsigned int);
	s->si = ft_itoa_base(s->i, f->conv, 'o');
	if (s->i < 0)
	{
		f->neg = 1;
		s->si = ft_itoa_base_neg(s->i, f->conv, 'o');
	}
	if (s->i == 0 && f->preci == 1 && f->hast == 0)
		s->si = "";
	if (f->hast == 1 && s->i == 0)
		f->hast = 0;
	if (f->hast == 1)
		f->champs -= 1;
	handle_o(f, s);
}
