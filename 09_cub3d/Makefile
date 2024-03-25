# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 13:16:50 by juhyelee          #+#    #+#              #
#    Updated: 2024/03/25 20:14:02 by juhyelee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCS		= includes
SRCS		= srcs/main.c \
			  srcs/init_map.c \
			  srcs/set_sources.c \
			  srcs/set_map.c \
			  srcs/get_string.c
OBJS		= ${SRCS:.c=.o}
LIBFTDIR	= libft
LIBFT		= ${LIBFTDIR}/libft.a
NAME		= cub3d

RM			= rm -rf
MK			= make
CC			= cc
CFLAG		= -Wall -Wextra -Werror -I${INCS}
LFLAG		= -Llibft -lft

.PHONY		: all clean fclean re
all			: ${NAME}
clean		:
	${RM} ${OBJS}
	${MK} clean -C ${LIBFTDIR}
fclean		: clean
	${RM} ${NAME}
	${MK} fclean -C ${LIBFTDIR}
re			: fclean all

${NAME}		: ${OBJS} ${LIBFT}
	${CC} $^ ${LFLAG} -o $@ -fsanitize=leak
${LIBFT}	:
	${MK} -C ${LIBFTDIR}
%.o			: %.c
	${CC} ${CFLAG} $< -o $@ -c
