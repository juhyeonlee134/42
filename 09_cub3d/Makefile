# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 11:02:51 by juhyelee          #+#    #+#              #
#    Updated: 2024/03/28 14:38:52 by juhyelee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFTDIR = libft
LIBFT = ${LIBFTDIR}/libft.a
INCS = includes
SRCS = srcs/main.c \
	   srcs/error.c \
	   srcs/get_line.c \
	   srcs/rsrc.c \
	   srcs/map1.c \
	   srcs/map2.c
OBJS = ${SRCS:.c=.o}

MK = make -C
RM = rm -rf
CC = cc
CFLAG = -Wall -Wextra -Werror -I${INCS} -g3
LFLAG = -Llibft -lft

NAME = cub3d

.PHONY : all clean fclean re

all : ${NAME}
clean :
	${RM} ${OBJS}
	${MK} ${LIBFTDIR} clean
fclean :
	${RM} ${OBJS}
	${RM} ${NAME}
	${MK} ${LIBFTDIR} fclean
re : fclean all

${NAME} : ${OBJS} ${LIBFT}
	${CC} ${LFLAG} $^ -o $@
${LIBFT} :
	${MK} ${LIBFTDIR}
%.o : %.c
	${CC} ${CFLAG} $< -o $@ -c
