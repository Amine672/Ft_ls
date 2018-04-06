/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:07:49 by akabbouc          #+#    #+#             */
/*   Updated: 2017/03/14 19:36:28 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		main(int ac, char **av)
{
	t_option	*o;
	t_file		*f;

	ac = 0;
	o = NULL;
	o = setup_o(o);
	f = NULL;
	f = parser(av + 1, o, f);
	f = ls_master(&f, o);
	return (0);
}
