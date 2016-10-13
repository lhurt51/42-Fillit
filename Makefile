# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhurt <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/02 14:26:47 by lhurt             #+#    #+#              #
#    Updated: 2016/10/02 14:26:48 by lhurt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =	gcc

FLAG =	-Wall -Wextra -Werror -o

NAME =	fillit

SRCS =	libft.a \
		check.c \
		tools.c \
		store.c \
		solve.c \
		hashfunc.c \
		main.c \

OBJS =	$(NAME)

all: 	$(NAME)

$(NAME):
		@$(CC) $(FLAG) $(NAME) $(SRCS)

clean:
		@/bin/rm -f $(OBJS)

fclean:	clean
		@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
