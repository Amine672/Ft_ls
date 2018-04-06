/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 17:46:56 by akabbouc          #+#    #+#             */
/*   Updated: 2017/02/20 17:46:58 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

t_file		*new_list_path(char *filename, char *path)
{
	t_file	*s;
	char	*tmp;

	if (!(s = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	s->name = filename;
	s->path = filename;
	tmp = ft_strjoin(path, "/");
	tmp = ft_strjoin(tmp, s->name);
	s->name = tmp;
	if (!(path == NULL))
		if (lstat(tmp, &s->filestat) != 0)
			return (0);
	if (path == NULL)
		if (lstat(filename, &s->filestat) != 0)
			return (0);
	s->next = NULL;
	return (s);
}

t_file		*new_list(char *filename)
{
	t_file *s;

	if (!(s = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	s->name = filename;
	s->next = NULL;
	return (s);
}

t_file		*pushfront(t_file *begin, t_file *new)
{
	new->next = begin;
	return (new);
}

void		swap_liste(t_file *tmp, t_file *tmp2)
{
	char *tmp3;

	tmp3 = tmp->name;
	tmp->name = tmp2->name;
	tmp2->name = tmp3;
}

void		order_list(t_file **begin, t_file *new, int (*cmp)())
{
	t_file *tmp;

	if (!*begin)
	{
		*begin = new;
		return ;
	}
	tmp = *begin;
	if (cmp(tmp->name, new->name) < 0)
	{
		*begin = pushfront(tmp, new);
		return ;
	}
	while (tmp && tmp->next)
	{
		if (cmp(tmp->next->name, new->name) < 0)
		{
			new->next = tmp->next;
			tmp->next = new;
			return ;
		}
		tmp = tmp->next;
	}
	if (tmp->next == NULL)
		tmp->next = new;
}
