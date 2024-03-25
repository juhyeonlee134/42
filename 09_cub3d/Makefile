# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 13:16:50 by juhyelee          #+#    #+#              #
#    Updated: 2024/03/25 21:45:57 by juhyelee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCS		= includes
GNL_SRCS	= srcs/gnl/gnl.c
MAP_SRCS	= srcs/map/init_map.c
TXT_SRCS	= srcs/text/init_text1.c \
			  srcs/text/init_text2.c
SRCS_SRCS	= srcs/srcs/init_srcs.c
SRCS		= srcs/main.c \
			  ${GNL_SRCS} \
			  ${MAP_SRCS} \
			  ${TXT_SRCS} \
			  ${SRCS_SRCS}
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
