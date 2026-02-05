# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/26 13:11:46 by jpedra-v          #+#    #+#              #
#    Updated: 2026/02/03 11:43:15 by jpedra-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
BONUS_NAME	= checker

SRC         = push_swap.c \
              check_input.c \
              utils.c \
              lib_utils.c \
              create_stack.c \
              basic_moves.c \
              rotate_moves.c \
              complex_moves.c \
              complex_moves_prep.c \
              complex_moves_do.c \
              get_next_line_utils.c \
              split.c

BONUS_SRC   = checker.c \
              get_next_line.c \
              get_next_line_utils.c \
              check_input.c \
              utils.c \
              lib_utils.c \
              create_stack.c \
              basic_moves.c \
              rotate_moves.c \
              split.c

OBJS = $(SRC:.c=.o)
BONUS_OBJS  = $(BONUS_SRC:.c=.o)

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

all:    $(NAME)

$(NAME): $(OBJS) Makefile
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) Makefile
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
