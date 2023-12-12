# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 21:11:29 by juhyelee          #+#    #+#              #
#    Updated: 2023/12/13 01:01:33 by juhyelee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAG=-Wall -Wextra -Werror

RM=rm -rf

INCS=includes
SRCS=srcs/main.c \
	 srcs/parse.c \
	 srcs/set_table.c \
	 srcs/doing.c \
	 srcs/time.c
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
	$(CC) $(OBJS) -o $(NAME)
%.o: %.c
	$(CC) $(CFLAG) -I$(INCS) $< -o $@ -c
