# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 20:58:29 by juhyelee          #+#    #+#              #
#    Updated: 2023/12/17 17:10:41 by juhyelee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAG=-Wall -Wextra -Werror
LFLAG=-pthread

RM=rm -rf

INCS=includes
SRCS=srcs/main.c \
	 srcs/parse.c \
	 srcs/init.c \
	 srcs/create.c \
	 srcs/thread.c
OBJS=$(SRCS:.c=.o)
NAME=philo

.PHONY: all clean fclean re

all: $(NAME)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

$(NAME): $(OBJS)
	$(CC) $(LFLAG) $(OBJS) -o $(NAME)
%.o: %.c
	$(CC) $(CFLAG) -I$(INCS) $< -o $@ -c
