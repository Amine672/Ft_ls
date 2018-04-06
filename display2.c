/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:21:51 by akabbouc          #+#    #+#             */
/*   Updated: 2017/03/24 14:21:53 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void		get_block(t_file *f)
{
	t_file	*tmp;
	int		i;

	if (!f)
		return ;
	i = 0;
	tmp = f;
	while (tmp)
	{
		if (lstat(tmp->name, &tmp->filestat) != 0)
			return ;
		i = tmp->filestat.st_blocks + i;
		tmp = tmp->next;
	}
	ft_printf("total %d\n", i);
}

void		get_time(struct stat filestat)
{
	char	*tmp;

	tmp = ctime((&filestat.st_mtime));
	tmp = ft_strsub(tmp, 4, 12);
	ft_printf("%s ", tmp);
	free(tmp);
}

void		permission(struct stat filestat)
{
	if ((S_ISLNK(filestat.st_mode)))
		ft_printf("l");
	else if ((S_ISDIR(filestat.st_mode)))
		ft_printf("d");
	else
		ft_printf("-");
	ft_printf((filestat.st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((filestat.st_mode & S_IWUSR) ? "w" : "-");
	ft_printf((filestat.st_mode & S_IXUSR) ? "x" : "-");
	ft_printf((filestat.st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((filestat.st_mode & S_IWGRP) ? "w" : "-");
	ft_printf((filestat.st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((filestat.st_mode & S_IROTH) ? "r" : "-");
	ft_printf((filestat.st_mode & S_IWOTH) ? "w" : "-");
	ft_printf((filestat.st_mode & S_IXOTH) ? "x" : "-");
}
