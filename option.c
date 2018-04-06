/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:56:26 by akabbouc          #+#    #+#             */
/*   Updated: 2017/02/20 15:03:42 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		options(char c, t_option *o)
{
	if (c == 'l')
		return (o->l = 1);
	if (c == 'R')
		return (o->rr = 1);
	if (c == 'r')
		return (o->r = 1);
	if (c == 'a')
		return (o->a = 1);
	if (c == 't')
		return (o->t = 1);
	if (c == '1')
	{
		o->l = 0;
		return (o->one = 1);
	}
	return (0);
}
