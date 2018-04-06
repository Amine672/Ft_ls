/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 02:33:47 by akabbouc          #+#    #+#             */
/*   Updated: 2017/01/10 02:33:48 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	conv_d(t_flags *f, t_stock *s)
{
	if (f->h == 1 && f->flags != 'D')
		s->i = (short)va_arg(s->ag, int);
	else if (f->hh == 1 && f->flags != 'D')
		s->i = (char)va_arg(s->ag, int);
	else if (f->l == 1 || f->flags == 'D' || f->jz == 1)
		s->i = va_arg(s->ag, long);
	else if (f->ll == 1)
		s->i = va_arg(s->ag, long long);
	else
		s->i = va_arg(s->ag, int);
	s->si = ft_itoa(s->i);
	if (s->i < 0)
		s->si = ft_strsub(s->si, 1, ft_strlen(s->si));
	handle_d(f, s);
}

void	conv_u(t_flags *f, t_stock *s)
{
	if (f->h == 1 && f->flags != 'U')
		s->i = (unsigned short)va_arg(s->ag, unsigned int);
	else if (f->hh == 1 && f->flags != 'U')
		s->i = (unsigned char)va_arg(s->ag, unsigned int);
	else if (f->l == 1 || f->flags == 'U' || f->jz == 1)
		s->i = va_arg(s->ag, unsigned long);
	else if (f->ll == 1)
		s->i = va_arg(s->ag, unsigned long long);
	else
		s->i = va_arg(s->ag, unsigned int);
	s->si = ft_uitoa(s->i);
	handle_d(f, s);
}
