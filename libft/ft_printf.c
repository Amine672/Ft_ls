/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 02:20:08 by akabbouc          #+#    #+#             */
/*   Updated: 2017/01/16 15:09:14 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_conv(t_flags *f, char c)
{
	char	*flag;
	int		i;

	flag = "sSpDioOuUdxXcC";
	i = 0;
	while (flag[i] && flag[i] != c)
		i++;
	f->flags = *(flag + i);
	if (i >= 14)
		return (-1);
	return (i);
}

int		print_until(t_stock *s)
{
	int		i;

	i = 0;
	while (s->str[i] != '\0' && s->str[i] != '%')
	{
		ft_putchar(s->str[i]);
		i++;
	}
	return (i);
}

int		ft_init(t_stock *s)
{
	int		i;
	t_flags	*f;

	f = set_flags();
	if (!(s->str = ft_strchr(s->str, '%')))
		return (0);
	s->str++;
	while ((i = get_conv(f, *s->str)) == -1 && *(s->str) != '\0')
	{
		ft_get_flags(f, s->str);
		if (f->pour == 1)
			break ;
		s->str++;
	}
	if (*(s->str) != '\0')
		s->str++;
	handle_conv(f, s);
	s->lenf += print_until(s);
	s->si = ft_strnew(0);
	ft_init(s);
	return (0);
}

int		ft_printf(const char *format, ...)
{
	t_stock	*s;

	s = set_stock();
	s->str = ft_strdup(format);
	s->lenf += print_until(s);
	va_start(s->ag, format);
	ft_init(s);
	va_end(s->ag);
	return (s->lenf);
}
