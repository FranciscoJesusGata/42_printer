# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/22 13:40:25 by fgata-va          #+#    #+#              #
#    Updated: 2020/01/23 17:30:54 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS += -Wall -Werror -Wextra

LIBOBJS = Libft/*.o

SRC = *.c

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

lib:
		$(MAKE) -C Libft all
$(NAME): lib
		@$(CC) $(CFLAGS) -c $(SRC)
		@ar rc $(NAME) $(OBJ) $(LIBOBJS)

clean: 
		@rm -f $(OBJ)
		@rm -f $(BONUSOBJS)

test: lib
	gcc -LLibft/ -lft -I. main.c ft_printf.c ft_chars_strings.c ft_printf_utils_1.c -o test

fclean: clean
		@rm -f $(NAME)
		@rm -f $(SONAME)

re: fclean all

all: $(NAME)