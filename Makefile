# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 15:05:50 by anvacca           #+#    #+#              #
#    Updated: 2024/09/18 12:14:45 by anvacca          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Files
SRC_SERVER =	./server.c \

SRC_CLIENT =	./client.c \

SRC_UTILS =	./utils/ft_putchar.c \
			./utils/ft_putnbr.c \
			./utils/ft_putstr.c \

OBJ_SERVER =	${SRC_SERVER:.c=.o} ${SRC_UTILS:.c=.o}
OBJ_CLIENT =	${SRC_CLIENT:.c=.o} ${SRC_UTILS:.c=.o}

# Variables
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g3 -fsanitize=address
RM		= rm -f

# Makefile
all:		server client

server:		${OBJ_SERVER}
		@${CC} ${CFLAGS} ${OBJ_SERVER} -o server

client:		${OBJ_CLIENT}
		@${CC} ${CFLAGS} ${OBJ_CLIENT} -o client
%.o:		%.c
		@${CC} ${CFLAGS} -c $? -o $@

clean:
		@${RM} ${OBJ_SERVER} ${OBJ_CLIENT}

fclean:		clean
		@${RM} server client

re:			fclean all

.PHONY: all server client clean fclean re
