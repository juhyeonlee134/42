# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 20:33:57 by juhyelee          #+#    #+#              #
#    Updated: 2024/01/20 13:07:22 by hywoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR	= libft
LIBFT		= ${LIBFT_DIR}/libft.a

INCS		= includes

PS_DIR		= srcs/parsing
PS_SRCS		= ${PS_DIR}/main.c \
			  ${PS_DIR}/signal.c \
			  ${PS_DIR}/tokenizer.c \
			  ${PS_DIR}/tokenizer2.c \
			  ${PS_DIR}/tools.c \
			  ${PS_DIR}/pipe_tree.c \
			  ${PS_DIR}/pipe_strdup.c \
			  ${PS_DIR}/parsing_error.c \
			  ${PS_DIR}/init_struct.c \
			  ${PS_DIR}/get_simple.c \
			  ${PS_DIR}/get_command.c \
			  ${PS_DIR}/free_pipe.c \
			  ${PS_DIR}/envp.c \
			  ${PS_DIR}/dollor.c \
			  ${PS_DIR}/dollor2.c \
			  ${PS_DIR}/make_rd.c \
			  ${PS_DIR}/tools2.c
PS_OBJS		= ${PS_SRCS:.c=.o}

EX_DIR		= srcs/execute
EX_SRCS		= ${EX_DIR}/execute.c \
			  ${EX_DIR}/file_1.c \
			  ${EX_DIR}/file_2.c \
			  ${EX_DIR}/command.c \
			  ${EX_DIR}/child.c \
			  ${EX_DIR}/setting.c \
			  ${EX_DIR}/builtin.c \
			  ${EX_DIR}/echo.c \
			  ${EX_DIR}/cd.c \
			  ${EX_DIR}/export.c \
			  ${EX_DIR}/env.c \
			  ${EX_DIR}/convert.c \
			  ${EX_DIR}/argument.c
EX_OBJS		= ${EX_SRCS:.c=.o}

SRCS		= ${PS_SRCS} \
			  ${EX_SRCS}
OBJS		= ${PS_OBJS} \
			  ${EX_OBJS}

NAME		= minishell

RM			= rm -rf
MK			= make -C ${LIBFT_DIR}
CC			= CC
IFLAG		= -I${INCS}
LFLAG		= -lreadline -lft -L${LIBFT_DIR}
CFLAG		= -Wall -Wextra -Werror

.PHONY : all clean fclean re

all : ${NAME}
clean :
	${RM} ${OBJS}
	${MK} clean
fclean : clean
	${RM} ${NAME}
	${MK} fclean
re : fclean all

${NAME} : ${OBJS} ${LIBFT}
	${CC} ${LFLAG} ${OBJS} -o ${NAME}
${LIBFT} :
	${MK}
	${MK} bonus
%.o : %.c
	${CC} ${CFLAG} $< -o $@ -c ${IFLAG}
