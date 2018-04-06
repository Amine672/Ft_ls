/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 02:32:40 by akabbouc          #+#    #+#             */
/*   Updated: 2017/01/10 02:32:41 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		handle_conv(t_flags *f, t_stock *s)
{
	if (f->flags == 'd' || f->flags == 'i' || f->flags == 'D')
	{
		f->hast = 0;
		conv_d(f, s);
	}
	if (f->flags == 'u' || f->flags == 'U')
		conv_u(f, s);
	if (f->flags == 'x' || f->flags == 'X' || f->flags == 'p')
	{
		f->conv = 16;
		conv_x(f, s);
	}
	if (f->flags == 'o' || f->flags == 'O')
	{
		f->conv = 8;
		conv_o(f, s);
	}
	if (f->flags == 'c' || f->flags == 'C')
		conv_c(f, s);
	if (f->pour == 1)
		handle_pour(f, s);
	if (f->flags == 's' || f->flags == 'S')
		conv_s(f, s);
}
