/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 19:03:26 by akabbouc          #+#    #+#             */
/*   Updated: 2017/02/21 19:03:27 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int			if_sort(t_file *f, int (*cmp)())
{
	t_file *tmp;

	tmp = f;
	while (tmp && tmp->next)
	{
		if (cmp(tmp->name, tmp->next->name) < 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_file		*sorting(t_file **f, int (*cmp)())
{
	t_file	*tmp;
	t_file	*begin_list;

	if (!*f)
		return (NULL);
	tmp = *f;
	begin_list = tmp;
	while (tmp && tmp->next)
	{
		if (cmp(tmp->name, tmp->next->name) < 0)
		{
			swap_liste(tmp, tmp->next);
			tmp = *f;
		}
		tmp = tmp->next;
	}
	return (*f);
}

t_file		*sort_list(t_file *f, t_option *o)
{
	t_file *tmp;

	tmp = f;
	if (o->t == 1 && o->r == 0)
		while (if_sort(f, cmp_time) > 0)
			f = sorting(&tmp, cmp_time);
	else if (o->r == 1 && o->t == 0)
		while (if_sort(f, cmp_r) > 0)
			f = sorting(&tmp, cmp_r);
	else if (o->r == 1 && o->t == 1)
		while (if_sort(f, cmp_time_r) > 0)
			f = sorting(&tmp, cmp_time_r);
	else
		while (if_sort(f, cmp) > 0)
			f = sorting(&tmp, cmp);
	return (f);
}
