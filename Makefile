# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/22 13:40:25 by fgata-va          #+#    #+#              #
#    Updated: 2020/02/04 19:46:55 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS += -Wall -Werror -Wextra

LIBOBJS = Libft/*.o

SRC = *.c

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

lib:
		@$(MAKE) -C Libft all
$(NAME): lib
		@$(CC) $(CFLAGS) -c $(SRC)
		@ar rc $(NAME) $(OBJ) $(LIBOBJS)

clean: 
		@rm -f $(OBJ)
		@$(MAKE) -C Libft clean

# Regla para compilar con programa con un main
test:
	$(CC) $(CFLAGS) -g -I./ $(SRC) Libft/*.c

fclean: clean
		@rm -f $(NAME)
		@$(MAKE) -C Libft fclean

re: fclean all

all: $(NAME)