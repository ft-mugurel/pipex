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

SRCS =	./src/pipex.c				\
				./src/pipex_utils.c	

SRCS_B =	./srcb/pipex_bonus.c				\
					./srcb/pipex_utils_bonus.c	\
					./srcb/error.c							\
					./srcb/exec_utils.c	
NAME = pipex
CC = gcc
CFLAGS = -g
LFLAGS = -I./include/ -I./lib/gnl-lib/include/ -I./lib/libft/
LIBFT = ./lib/libft/libft.a
GET_NEXT_LINE = ./lib/gnl-lib/get_next_line.a
RM = rm -rf
LIBC = ar -rcs

all: ${NAME}

$(NAME): $(SRCS) ${LIBFT} $(GET_NEXT_LINE)
	@gcc $(CFLAGS) $(LFLAGS) $(SRCS) $(GET_NEXT_LINE) $(LIBFT) -o $(NAME)

bonus:  $(SRCS_B) ${LIBFT} $(GET_NEXT_LINE)
	@gcc $(CFLAGS) $(LFLAGS) $(SRCS_B) $(GET_NEXT_LINE) $(LIBFT) -o $(NAME)

$(LIBFT) :
	@make -C ./lib/libft/

$(GET_NEXT_LINE):
	@make -C ./lib/gnl-lib

norm:
		@norminette

clean:
	@${RM} ${OBJS}
	@make clean -C ./lib/gnl-lib
	@make clean -C ./lib/libft

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C ./lib/gnl-lib
	@make fclean -C ./lib/libft

re: fclean all

.PHONY: all bonus clean fclean re .c.o
