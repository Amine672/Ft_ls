/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 17:48:01 by akabbouc          #+#    #+#             */
/*   Updated: 2017/02/20 17:48:01 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		cmp(const char *s1, const char *s2)
{
	return (ft_memcmp(s2, s1, ft_strlen(s1) + 1));
}

int		cmp_r(const char *s1, const char *s2)
{
	return (ft_memcmp(s1, s2, ft_strlen(s2) + 1));
}

int		cmp_time(const char *s1, const char *s2)
{
	struct stat a;
	struct stat b;

	lstat(s1, &a);
	lstat(s2, &b);
	return (a.st_mtime - b.st_mtime);
}

int		cmp_time_r(const char *s1, const char *s2)
{
	struct stat a;
	struct stat b;

	lstat(s1, &a);
	lstat(s2, &b);
	return (b.st_mtime - a.st_mtime);
}
