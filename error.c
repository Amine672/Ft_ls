/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:50:48 by akabbouc          #+#    #+#             */
/*   Updated: 2017/02/20 14:50:50 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void		o_error(char c)
{
	ft_printf("ft_ls: illegal option -- %c\n", c);
	ft_printf("usage: ft_ls [-lraRt1] [file ...]\n");
	exit(1);
}

void		f_error(t_file *f)
{
	ft_putstr_fd("ft_ls: ", 2);
	perror(f->name);
}

void		free_list(t_file **tmp, t_file **prev)
{
	(*prev)->next = (*tmp)->next;
	free(*tmp);
	(*tmp) = (*prev)->next;
}

void		display_err(t_file *f)
{
	t_file *tmp;

	tmp = f;
	while (tmp)
	{
		ft_putstr_fd("ft_ls: ", 2);
		perror(tmp->name);
		tmp = tmp->next;
	}
}
