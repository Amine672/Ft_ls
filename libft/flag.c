/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 02:30:09 by akabbouc          #+#    #+#             */
/*   Updated: 2017/01/10 02:30:12 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_get_flags(t_flags *f, char *c)
{
	ft_get_flags2(f, c);
	if (*c == '.')
	{
		f->preci = 1;
		f->preci_len = ft_atoi(c + 1);
	}
	if (ft_isdigit(*c) && f->champs == 0 && f->preci == 0)
		f->champs = ft_atoi(c);
	if (*c == 'h' && *(c + 1) == 'h')
		f->hh = 1;
	if (*c == 'h' && f->hh == 0)
		f->h = 1;
	if (*c == 'l' && *(c + 1) == 'l')
		f->ll = 1;
	if (*c == 'l' && f->ll == 0)
		f->l = 1;
	if (*c == 'j' || *c == 'z')
		f->jz = 1;
}

void		ft_get_flags2(t_flags *f, char *c)
{
	if (*c == '#')
		f->hast = 1;
	if (*c == '-')
		f->left = 1;
	if (*c == '+')
		f->plus = 1;
	if (*c == ' ')
		f->blank = 1;
	if (*c == '0' && f->preci == 0 && f->champs == 0)
		f->zero = 1;
	if (*c == '%')
		f->pour = 1;
}
