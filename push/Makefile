# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/26 13:11:46 by jpedra-v          #+#    #+#              #
#    Updated: 2026/01/29 16:37:23 by jpedra-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRC	=	push_swap.c		\
		check_input.c		\
		utils.c			\
		create_stack.c		\
		basic_moves.c		\
		rotate_moves.c		\
		complex_moves.c		\
		complex_moves_prep.c	\
		complex_moves_do.c	\

OBJS = $(SRC:.c=.o)

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g
AR = ar crs

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c -o $@ $<

all:	$(NAME)

$(NAME): $(OBJS) Makefile
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
