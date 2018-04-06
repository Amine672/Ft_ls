/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 02:38:39 by akabbouc          #+#    #+#             */
/*   Updated: 2017/01/10 02:38:40 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		handle_d(t_flags *f, t_stock *s)
{
	if (ft_strcmp(s->si, "0") == 0 && f->preci == 1)
		s->si = "";
	if (f->left == 1)
		f->zero = 0;
	if (f->champs <= (int)ft_strlen(s->si))
		f->champs = 0;
	if (f->plus == 1)
		f->blank = 0;
	if (f->preci_len < 0)
		f->champs = 0;
	if (f->flags == 'u' || f->flags == 'U')
	{
		f->neg = 1;
		f->blank = 0;
		f->plus = 0;
	}
	print_d(f, s);
}

void		print_d(t_flags *f, t_stock *s)
{
	if (f->flags == 'p' && f->preci == 0 && f->zero == 1)
		f->champs -= 2;
	get_zero(f, s);
	get_signe(f, s);
	get_space(f, s);
	if (f->hast == 1 && s->i != 0)
	{
		if (f->flags == 'X')
			s->si = ft_strjoin("0X", s->si);
		if (f->flags == 'x')
			s->si = ft_strjoin("0x", s->si);
	}
	if (f->flags == 'p')
		s->si = ft_strjoin("0x", s->si);
	if (f->hast == 1 && s->i != 0 && (f->flags == 'o' || f->flags == 'O'))
		s->si = ft_strjoin("0", s->si);
	if (f->left == 1)
		s->si = ft_strjoin(s->si, s->sp);
	else
		s->si = ft_strjoin(s->sp, s->si);
	s->lenf += ft_strlen(s->si);
	ft_putstr(s->si);
}

void		handle_pour(t_flags *f, t_stock *s)
{
	if (f->preci == 1)
		f->preci_len = 0;
	if (f->preci == 1 && f->zero == 1)
		f->preci = 0;
	f->champs -= 1;
	if (f->hast == 1 || f->plus == 1)
	{
		f->plus = 0;
		f->hast = 0;
	}
	get_zero(f, s);
	get_signe(f, s);
	get_space(f, s);
	if (f->left == 1)
		s->si = ft_strjoin("%", s->sp);
	else if (f->zero == 1)
		s->si = ft_strjoin(s->tmp, "%");
	else
		s->si = ft_strjoin(s->sp, "%");
	s->lenf += ft_strlen(s->si);
	ft_putstr(s->si);
}

void		print_c(t_flags *f, t_stock *s)
{
	if (f->preci == 1 && f->preci_len <= f->champs)
		f->preci_len = 0;
	if (f->zero == 1 && f->left == 0)
		ft_putstr(s->tmp);
	if (f->left == 1)
	{
		f->flags == 'C' ? ft_putwchar(s->wc) : ft_putchar(s->s);
		ft_putstr(s->sp);
	}
	else
	{
		ft_putstr(s->sp);
		f->flags == 'C' ? ft_putwchar(s->wc) : ft_putchar(s->s);
	}
	s->wi = (f->flags == 'C') ? ft_wcharlen(s->wc) : 1;
	s->lenf = ft_strlen(s->tmp) + ft_strlen(s->sp) + s->wi + s->lenf;
}
