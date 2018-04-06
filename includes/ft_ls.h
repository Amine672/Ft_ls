/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:11:40 by akabbouc          #+#    #+#             */
/*   Updated: 2017/03/27 19:35:12 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include "../libft/libft.h"
# include <errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/dir.h>
# include <time.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <pwd.h>

typedef struct			s_option
{
	int					i;
	int					j;
	int					l;
	int					tm;
	int					r;
	int					rr;
	int					a;
	int					t;
	int					one;
}						t_option;

typedef struct			s_file
{
	char				*name;
	char				*path;
	int					data;
	struct s_file		*next;
	struct stat			filestat;
}						t_file;

int						get_lnk(char *name, struct stat filestat);
t_file					*tools_dir(char *path, DIR *dir, t_option *o);
t_file					**directory(t_file **f, t_option *o);
t_file					**file(t_file **f, t_option *o);
void					get_block(t_file *f);
t_file					*ft_ls(char *path, t_option *o);
void					delete_liste(t_file *tmp, t_file **f);
void					display_file(char *name, t_option *o);
void					display_file_l(char *name);
void					get_time(struct stat filestat);
void					swap_liste(t_file *tmp, t_file *tmp2);
t_file					*sorting(t_file **f, int (*cmp)());
t_file					*sort_list(t_file *f, t_option *o);
int						if_sort(t_file *f, int (*cmp)());
t_file					*sort_recu(t_file *f, int (*cmp)());
t_file					*ls_master(t_file **f, t_option *o);
void					display(t_file *f, t_option *o);
void					display_err(t_file *f);
int						cmp(const char *s1, const char *s2);
int						cmp_r(const char *s1, const char *s2);
int						cmp_time(const char *s1, const char *s2);
int						cmp_time_r(const char *s1, const char *s2);
void					order_list(t_file **begin, t_file *new, int (*cmp)());
int						ls_r(t_file *f, t_option *o);
t_file					*pushfront(t_file *begin, t_file *new);
t_file					*new_list(char *filename);
t_file					*new_list_path(char *filename, char *path);
t_file					*parse_err(t_file *f, t_option *o);
t_file					*get_args(char **args, int i, t_file *f);
void					permission(struct stat filestat);
void					display_l(t_file *f, t_option *o);
void					ls_display(t_file *f, t_option *o);
t_file					*parser(char **args, t_option *o, t_file *l);
int						main(int ac, char **av);
int						parse_option(char **args, int i, t_option *o);
void					o_error(char c);
void					f_error(t_file *s);
t_option				*setup_o(t_option *o);
t_file					*setup_f(t_file *f);
void					free_list(t_file **tmp, t_file **prev);
int						options(char c, t_option *o);

#endif
