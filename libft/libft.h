/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:19:07 by akabbouc          #+#    #+#             */
/*   Updated: 2016/11/13 03:27:27 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_stock
{
	va_list			(ag);
	char			*str;
	char			*tmp;
	char			*sp;
	char			*si;
	char			s;
	long long		i;
	char			*sa;
	int				lenf;
	int				wi;
	wchar_t			*wtmp;
	wchar_t			*ws;
	wchar_t			wc;
	int				len_aq;
	char			*aq;
	char			*st;
	int				tlen;
	int				len;
}					t_stock;

typedef struct		s_flags
{
	char			flags;
	int				hast;
	int				left;
	int				champs;
	int				plus;
	int				blank;
	int				zero;
	int				pour;
	int				preci;
	int				preci_len;
	int				point;
	int				afterpour;
	int				h;
	int				hh;
	int				l;
	int				ll;
	int				jz;
	int				t;
	int				q;
	int				neg;
	int				conv;
}					t_flags;

char				*ft_uitoa(unsigned long int n);
char				*ft_itoa_short(short n);
char				*ft_tkt2(char c);
char				*ft_itoa_base_neg(unsigned long int n, int i, char c);
char				*ft_tkt(char c);
char				*ft_itoa_base(long int n, int i, char c);
void				print_s(t_flags *f, t_stock *s);
void				ft_putwstr(wchar_t *c);
void				ft_putwchar(wchar_t c);
size_t				ft_wcharlen(wchar_t c);
int					count_bits(unsigned int nbr);
void				ft_get_flags2(t_flags *f, char *c);
void				*ft_strset(int c, size_t len);
size_t				ft_strnwlen(t_stock *s, t_flags *f);
int					ft_cstrwlen(t_stock *s, t_flags *f);
int					ft_putnwchar(t_stock *s, t_flags *f);
void				ft_putnwstr(t_stock *s, t_flags *f);
void				get_zero_s(t_flags *f, t_stock *s);
void				get_space_s(t_flags *f, t_stock *s);
void				handle_s(t_flags *f, t_stock *s);
void				conv_s(t_flags *f, t_stock *s);
void				handle_pour(t_flags *f, t_stock *s);
void				print_c(t_flags *f, t_stock *s);
void				handle_c(t_flags *f, t_stock *s);
void				conv_c(t_flags *f, t_stock *s);
void				conv_o(t_flags *f, t_stock *s);
int					ft_printf(const char *format, ...);
t_stock				*set_stock(void);
t_flags				*set_flags(void);
void				handle_conv(t_flags *f, t_stock *s);
void				handle_d(t_flags *f, t_stock *s);
void				conv_d(t_flags *f, t_stock *s);
void				ft_get_flags(t_flags *f, char *c);
void				get_signe(t_flags *f, t_stock *s);
void				get_zero(t_flags *f, t_stock *s);
void				get_space(t_flags *f, t_stock *s);
void				print_d(t_flags *f, t_stock *s);
void				conv_u(t_flags *f, t_stock *s);
void				conv_x(t_flags *f, t_stock *s);
void				ft_test(t_stock *s, t_flags *f);
int					ft_isascii(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_atoi(const char *str);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *src, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putstr(char const *s);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strrchr(const char *s, int c);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *l, size_t len);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isprint(int c);
size_t				ft_strnlen(const char *s, size_t len);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *neww);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_itoa(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
char				*ft_itoa(int n);
char				**ft_strsplit(char const *s, char c);
char				*ft_strtrim(char const *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t n);
int					ft_strneau(char const *s1, char const *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strmap(char const *s, char (*f)(char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *));
void				ft_strclr(char *s);
void				ft_strdel(char **as);
char				*ft_strnew(size_t size);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);

#endif
