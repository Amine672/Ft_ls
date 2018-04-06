/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 22:43:31 by akabbouc          #+#    #+#             */
/*   Updated: 2017/01/14 22:43:33 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	get_zero_s(t_flags *f, t_stock *s)
{
	int i;

	i = 0;
	if (f->preci == 1)
		s->sa = ft_strsub(s->sa, 0, f->preci_len);
	if (f->champs > 0 && f->zero == 1)
	{
		i = (f->flags == 'S') ? ft_strnwlen(s, f) : ft_strlen(s->sa);
		f->champs -= i;
	}
	if (f->champs < 0)
		f->champs = 0;
	s->tmp = ft_strset('0', f->champs);
}

void	get_space_s(t_flags *f, t_stock *s)
{
	int i;

	i = 0;
	if (f->preci == 1)
		s->sa = ft_strsub(s->sa, 0, f->preci_len);
	if (f->champs > 0 && f->zero == 0)
	{
		i = (f->flags == 'S') ? ft_strnwlen(s, f) : ft_strlen(s->sa);
		f->champs -= i;
	}
	if (f->champs < 0)
		f->champs = 0;
	if (f->champs > 0)
		s->sp = ft_strset(' ', f->champs);
}
