# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 13:16:50 by juhyelee          #+#    #+#              #
#    Updated: 2024/03/20 14:29:44 by juhyelee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCS		= includes
SRCS		= srcs/main.c \
			  srcs/set_textures.c \
			  srcs/get_string.c
OBJS		= ${SRCS:.c=.o}
LIBFTDIR	= libft
LIBFT		= ${LIBFTDIR}/libft.a
NAME		= cub3d

RM			= rm -rf
MK			= make
CC			= cc
CFLAG		= -Wall -Wextra -Werror -I${INCS} -g3
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
	${CC} $^ ${LFLAG} -o $@
${LIBFT}	:
	${MK} -C ${LIBFTDIR}
%.o			: %.c
	${CC} ${CFLAG} $< -o $@ -c
