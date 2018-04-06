/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 17:41:04 by akabbouc          #+#    #+#             */
/*   Updated: 2017/02/21 17:41:06 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

t_file		*ls_master(t_file **f, t_option *o)
{
	t_file		*tmp;

	*f = sort_list(*f, o);
	tmp = NULL;
	if (*f == NULL && o->i == 0)
	{
		tmp = ft_ls(".", o);
		if (o->rr == 1)
			*f = tmp;
	}
	f = file(f, o);
	f = directory(f, o);
	return (*f);
}

int			ls_r(t_file *f, t_option *o)
{
	t_file *tmp;

	if (!f)
		return (0);
	if (f && f->next)
		ft_printf("\n");
	f = ft_ls(f->name, o);
	tmp = f;
	delete_liste(tmp, &f);
	if (f)
	{
		tmp = f;
		while (tmp)
		{
			ls_r(tmp, o);
			tmp = tmp->next;
		}
		free(tmp);
	}
	return (0);
}

t_file		*ft_ls(char *path, t_option *o)
{
	t_file			*file;
	DIR				*dir;

	file = NULL;
	if (ft_strcmp(path, ".") != 0)
		ft_printf("%s:\n", path);
	dir = opendir(path);
	if (dir == NULL)
		return (NULL);
	file = tools_dir(path, dir, o);
	if (o->l == 1)
		get_block(file);
	ls_display(file, o);
	closedir(dir);
	return (file);
}
