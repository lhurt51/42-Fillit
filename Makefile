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

LIBFT = libft/

COMP =	make -C $(LIBFT) re

COMPC = make -C $(LIBFT) clean

COMPF = make -C $(LIBFT) fclean

NAME =	fillit

SRCS =	$(LIBFT)libft.a \
		check.c \
		tools.c \
		store.c \
		solve.c \
		hashfunc.c \
		main.c \

all: 	$(NAME)

$(NAME):
		@$(COMP)
		@$(CC) $(FLAG) $(NAME) $(SRCS)

clean:
		@$(COMPC)

fclean:	clean
		@$(COMPF)
		@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
