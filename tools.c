/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:17:43 by akabbouc          #+#    #+#             */
/*   Updated: 2017/03/22 14:17:45 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void		delete_liste(t_file *tmp, t_file **f)
{
	t_file *prev;

	prev = NULL;
	while (tmp)
	{
		if (lstat(tmp->name, &tmp->filestat) != 0)
			return ;
		if (S_ISREG(tmp->filestat.st_mode))
		{
			if (!prev)
			{
				(*f) = (*f)->next;
				free(tmp);
				if (!(tmp = *f))
					break ;
			}
			else
				free_list(&tmp, &prev);
		}
		else
		{
			prev = tmp;
			tmp = tmp->next;
		}
	}
}

t_file		**file(t_file **f, t_option *o)
{
	t_file		*tmp;
	struct stat filestat;

	if (!f)
		return (0);
	tmp = *f;
	while (tmp)
	{
		if (lstat(tmp->name, &filestat) != 0)
			break ;
		if (S_ISREG(filestat.st_mode) && o->rr == 0)
			display_file(tmp->name, o);
		tmp = tmp->next;
	}
	tmp = *f;
	delete_liste(tmp, f);
	return (f);
}

t_file		**directory(t_file **f, t_option *o)
{
	t_file *tmp;
	t_file *tmp2;

	if (!f)
		return (0);
	tmp2 = NULL;
	tmp = *f;
	while (tmp)
	{
		if (lstat(tmp->name, &tmp->filestat) != 0)
			break ;
		if (S_ISDIR(tmp->filestat.st_mode))
		{
			if (o->rr == 1)
				ls_r(tmp, o);
			else
				tmp2 = ft_ls(tmp->name, o);
			if (tmp && tmp->next && o->rr == 0)
				ft_printf("\n");
		}
		tmp = tmp->next;
	}
	return (f);
}

int			get_lnk(char *name, struct stat filestat)
{
	char	*linkname;
	ssize_t r;
	ssize_t bufsiz;

	if (S_ISLNK(filestat.st_mode))
	{
		bufsiz = filestat.st_size + 1;
		linkname = ft_memalloc(bufsiz);
		r = readlink(name, linkname, bufsiz);
		if (r == -1)
			return (0);
		linkname[r] = '\0';
		ft_printf("%s -> %s\n", name, linkname);
		return (1);
	}
	return (0);
}

t_file		*tools_dir(char *path, DIR *dir, t_option *o)
{
	t_file			*file;
	struct dirent	*sd;

	file = NULL;
	while ((sd = readdir(dir)) != NULL)
	{
		if (ft_strncmp(sd->d_name, ".", 1) == 0 && (o->a == 0 || o->rr == 1))
			continue;
		if (o->t == 1 && o->r == 0)
			order_list(&file, new_list_path(sd->d_name, path), cmp_time);
		else if (o->r == 1 && o->t == 0)
			order_list(&file, new_list_path(sd->d_name, path), cmp_r);
		else if (o->r == 1 && o->t == 1)
			order_list(&file, new_list_path(sd->d_name, path), cmp_time_r);
		else
			order_list(&file, new_list_path(sd->d_name, path), cmp);
	}
	return (file);
}
