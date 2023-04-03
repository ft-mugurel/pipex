#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 02:36:36 by mugurel           #+#    #+#              #
#    Updated: 2022/12/19 23:07:38 by mugurel          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCS	=	./src/get_next_line.c					\
				./src/get_next_line_utils.c		\

BSRCS =	./srcb/get_next_line_bonus.c					\
				./srcb/get_next_line_utils_bonus.c		\

BOBJS = $(BSRCS:.c=.o)
OBJS = ${SRCS:.c=.o}
NAME = get_next_line.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I./include/
RM = rm -rf
LIBC = ar rc

all: ${NAME}

${NAME}: ${OBJS}
	@${LIBC} ${NAME} ${OBJS}
	@echo "Success"

${LIBC}: ${NAME} ${OBJS}

bonus: ${OBJS} ${BOBJS}
	${LIBC} ${NAME} ${OBJS} ${BOBJS}

clean:
	${RM} ${OBJS} ${BOBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
