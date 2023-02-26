#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 04:45:20 by mugurel           #+#    #+#              #
#    Updated: 2023/02/06 04:45:22 by mugurel          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCS = ./src/pipex.c
SRCBS = 
NAME = pipex
CC = gcc
CFLAGS =  -g
LIB = ./lib/lib/libft.a
RM = rm -rf
LIBC = ar -rcs

all: ${NAME}

$(NAME): $(SRCS)
	@gcc $(CFLAGS) $(LFLAGS) $(SRCS) $(LIB) -o $(NAME)

bonus : $(SRCBS) $(MLX) $(FT_PRINTF) $(GET_NEXT_LINE)
	@gcc $(CFLAGS) $(LFLAGS) $(SRCBS) $(FT_PRINTF) $(GET_NEXT_LINE) -o $(NAME)

clean:

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re .c.o
