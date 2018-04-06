/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 06:32:38 by akabbouc          #+#    #+#             */
/*   Updated: 2017/01/19 06:32:40 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwstr(wchar_t *c)
{
	while (c && *c)
		ft_putwchar(*c++);
}

void	ft_putnwstr(t_stock *s, t_flags *f)
{
	s->wi = 0;
	while (s->ws && *s->ws)
	{
		if (ft_putnwchar(s, f) == -1)
			return ;
		s->ws++;
	}
}
