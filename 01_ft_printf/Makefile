# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 18:57:47 by juhyelee          #+#    #+#              #
#    Updated: 2023/04/06 13:29:53 by juhyelee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES : .c .o

CC = cc
CFLAG = -Wall -Wextra -Werror
SRCS = ft_printf.c util.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a

.PHONY : all, clean, fclean, re, bonus

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcus $@ $^

%.o : %.c
	$(CC) $(CFLANG) -o $@ -c $<

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
