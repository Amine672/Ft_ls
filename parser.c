/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:31:54 by akabbouc          #+#    #+#             */
/*   Updated: 2017/03/24 14:14:12 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

t_file		*parser(char **args, t_option *o, t_file *f)
{
	int i;

	i = 0;
	i = parse_option(args, i, o);
	f = get_args(args, i, f);
	f = parse_err(f, o);
	return (f);
}

int			parse_option(char **args, int i, t_option *o)
{
	int j;

	j = 1;
	i = 0;
	while (args[i] && args[i][0] == '-')
	{
		while (args[i][j])
		{
			if (!options(args[i][j], o))
				o_error(args[i][j]);
			j++;
		}
		j = 1;
		i++;
	}
	return (i);
}

t_file		*parse_err(t_file *f, t_option *o)
{
	t_file		*tmp;
	struct stat filestat;

	if (!f)
		return (NULL);
	if (lstat(f->name, &filestat) == -1)
	{
		tmp = f;
		f_error(tmp);
		f = parse_err(f->next, o);
		o->i = 1;
	}
	else
	{
		f->filestat = filestat;
		if (f && f->next)
			f->next = parse_err(f->next, o);
	}
	return (f);
}

t_file		*get_args(char **args, int i, t_file *f)
{
	while (args[i] != NULL)
	{
		order_list(&f, new_list(args[i]), cmp);
		i++;
	}
	return (f);
}
