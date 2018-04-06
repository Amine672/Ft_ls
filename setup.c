/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:15:15 by akabbouc          #+#    #+#             */
/*   Updated: 2017/02/20 14:15:16 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

t_option	*setup_o(t_option *o)
{
	if (!(o = (t_option*)malloc(sizeof(t_option))))
		return (NULL);
	o->l = 0;
	o->i = 0;
	o->j = 0;
	o->a = 0;
	o->r = 0;
	o->rr = 0;
	o->t = 0;
	o->one = 0;
	return (o);
}

t_file		*setup_f(t_file *f)
{
	if (!(f = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	f->name = NULL;
	f->path = NULL;
	return (NULL);
}
