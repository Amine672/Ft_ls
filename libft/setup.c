/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 02:39:13 by akabbouc          #+#    #+#             */
/*   Updated: 2017/01/10 02:39:14 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stock		*set_stock(void)
{
	t_stock *s;

	if (!(s = (t_stock*)ft_memalloc(sizeof(t_stock))))
		return (0);
	s->tmp = ft_strnew(0);
	s->i = 0;
	s->len = 0;
	s->sp = ft_strnew(0);
	s->si = ft_strnew(0);
	s->sa = ft_strnew(0);
	s->lenf = 0;
	s->wi = 0;
	s->tlen = 0;
	s->st = ft_strnew(0);
	s->aq = ft_strnew(0);
	s->len_aq = 0;
	return (s);
}

t_flags		*set_flags(void)
{
	t_flags *f;

	f = (t_flags*)ft_memalloc(sizeof(t_flags));
	f->flags = 0;
	f->champs = 0;
	f->hast = 0;
	f->left = 0;
	f->plus = 0;
	f->blank = 0;
	f->zero = 0;
	f->pour = 0;
	f->preci = 0;
	f->preci_len = 0;
	f->point = 0;
	f->afterpour = 0;
	f->h = 0;
	f->l = 0;
	f->ll = 0;
	f->jz = 0;
	f->neg = 0;
	f->conv = 0;
	f->hh = 0;
	return (f);
}
