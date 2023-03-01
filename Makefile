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

SRCS =	./src/pipex.c			\
				./src/ft_execvp.c	
OBJS = ${SRCS:.c=.o}
NAME = pipex
CC = gcc
CFLAGS = -g
LIBFT = ./lib/libft/libft.a
RM = rm -rf
LIBC = ar -rcs

all: ${NAME}

$(NAME): $(SRCS) ${LIBFT}
	@gcc $(CFLAGS) $(LFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

$(LIBFT) :
	@make -C ./lib/libft/

clean:
	@${RM} ${OBJS}
	@make clean -C ./lib/libft/

fclean: clean
	@${RM} ${NAME} ${LIBFT}

re: fclean all

.PHONY: all bonus clean fclean re .c.o
