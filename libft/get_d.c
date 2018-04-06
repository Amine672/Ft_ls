/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 03:23:56 by akabbouc          #+#    #+#             */
/*   Updated: 2017/01/10 03:23:58 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		len_zero(t_flags *f, t_stock *s)
{
	int len;

	len = ft_strlen(s->si);
	if (s->i < 0 || ((f->blank == 1 || f->plus == 1) && s->i >= 0))
		len = (f->preci_len <= 0) ? len += 1 : len;
	if (f->preci_len < 0)
	{
		f->champs = f->preci_len * -1;
		f->preci_len = 0;
	}
	if (f->preci == 1)
	{
		len = f->preci_len - len;
		if (f->flags == 'c')
			len = f->champs - 1;
	}
	else
		len = f->champs - len;
	if (f->flags == 'c' && f->zero == 1)
		len = f->champs - 1;
	len = (f->zero == 0 && f->preci == 0) ? 0 : len;
	len = (f->hast == 1 && f->conv == 8) ? len -= 1 : len;
	len = (f->hast == 1 && f->conv == 16 && f->zero == 1) ? len -= 2 : len;
	return (len = (len < 0) ? 0 : len);
}

void	get_signe(t_flags *f, t_stock *s)
{
	if (f->plus == 1 && s->i >= 0)
		s->si = ft_strjoin("+", s->si);
	if (s->i < 0 && f->neg != 1)
		s->si = ft_strjoin("-", s->si);
	if (f->blank == 1 && s->i >= 0)
		s->si = ft_strjoin(" ", s->si);
}

void	get_zero(t_flags *f, t_stock *s)
{
	int len;

	len = len_zero(f, s);
	s->tmp = ft_strset('0', len);
	if (f->flags == 'p' && s->si == 0 && f->zero == 1)
		s->si = ft_strjoin(s->si, s->tmp);
	else
		s->si = ft_strjoin(s->tmp, s->si);
}

void	get_space(t_flags *f, t_stock *s)
{
	int len;

	len = ft_strlen(s->si);
	if (f->flags == 'p')
		len += 2;
	if (f->flags == 'c')
		len = 1;
	if (f->hast == 1 && f->conv == 16 && f->preci_len <= 0)
		len += 2;
	if (f->champs > 0)
	{
		len = (f->flags == 'C') ? ft_wcharlen(s->wc) : len;
		f->champs -= len;
		if (f->champs < 0)
			f->champs = 0;
		s->sp = ft_strset(' ', f->champs);
	}
	if (f->flags == 'c' && f->zero == 1 && f->left == 0)
		s->sp = ft_strnew(0);
}
