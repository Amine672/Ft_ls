/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 18:02:17 by akabbouc          #+#    #+#             */
/*   Updated: 2017/02/20 18:02:18 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	display(t_file *f, t_option *o)
{
	if (ft_strncmp(f->path, ".", 1) == 0 && o->a == 0)
		f = f->next;
	else
		ft_printf("%s\n", f->path);
}

void	display_file_l(char *name)
{
	struct stat		filestat;
	struct group	*grp;

	if (lstat(name, &filestat) != 0)
		return ;
	permission(filestat);
	ft_printf("%3d", filestat.st_nlink);
	ft_printf(" %8s ", getpwuid(filestat.st_uid)->pw_name);
	if ((grp = getgrgid(filestat.st_gid)) != NULL)
		ft_printf("%10s", grp->gr_name);
	ft_printf(" %5d ", filestat.st_size);
	get_time(filestat);
	ft_printf("%s\n", name);
}

void	display_file(char *name, t_option *o)
{
	if (o->l == 1)
		display_file_l(name);
	else
		ft_printf("%s\n", name);
}

void	ls_display(t_file *f, t_option *o)
{
	t_file *tmp;

	tmp = f;
	if (!f)
		return ;
	while (tmp)
	{
		if (o->l == 1)
			display_l(tmp, o);
		else
			display(tmp, o);
		tmp = tmp->next;
	}
}

void	display_l(t_file *f, t_option *o)
{
	struct group	*grp;

	if (lstat(f->name, &f->filestat) != 0)
		return ;
	if (ft_strncmp(f->path, ".", 1) == 0 && o->a == 0)
		f = f->next;
	else
	{
		permission(f->filestat);
		ft_printf("%3d", f->filestat.st_nlink);
		ft_printf(" %8s ", getpwuid(f->filestat.st_uid)->pw_name);
		if ((grp = getgrgid(f->filestat.st_gid)) != NULL)
			ft_printf("%10s", grp->gr_name);
		ft_printf(" %5d ", f->filestat.st_size);
		get_time(f->filestat);
		if ((!get_lnk(f->path, f->filestat)))
			ft_printf("%s\n", f->path);
	}
}
