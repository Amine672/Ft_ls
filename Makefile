# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/27 18:22:46 by akabbouc          #+#    #+#              #
#    Updated: 2017/03/27 18:22:49 by akabbouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      =   gcc
RM      =   rm -f
CFLAGS  =   -Wall -Wextra -Werror
LIB		=	-L./libft -lft
NAME    =   ft_ls
SRCS    =   add_list.c 			\
			cmp.c 				\
			display.c 			\
			display2.c 			\
			error.c 			\
			handle.c 			\
			main.c 				\
			option.c 			\
			parser.c 			\
			setup.c 			\
			sort.c 				\
			tools.c

OBJS    =   $(SRCS:.c=.o)

all:        $(NAME)

$(NAME):    $(OBJS)
			Make -C ./libft
			$(CC) -o $(NAME) $(OBJS) $(LIB)

clean:
		$(RM) $(OBJS)
		Make -C ./libft fclean

fclean:     clean
	$(RM) $(NAME)

re:         fclean all

.PHONY:     all clean fclean re
