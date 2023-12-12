# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhyelee <juhyelee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 15:22:44 by juhyelee          #+#    #+#              #
#    Updated: 2023/11/09 15:22:45 by juhyelee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/main.c \
	   srcs/parse.c \
	   srcs/indexing.c \
	   srcs/stack_find.c \
	   srcs/stack_ins.c \
	   srcs/stack_insert.c \
	   srcs/stack_remove.c \
	   srcs/instruction_execute.c \
	   srcs/instruction_ins_1.c \
	   srcs/instruction_ins_2.c \
	   srcs/sort_cheap.c \
	   srcs/sort_optimization.c \
	   srcs/sort_push.c \
	   srcs/sort.c
OBJS = $(SRCS:.c=.o)
INCDIR = includes
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

CC = cc
CFLAG = -Wall -Wextra -Werror -I$(INCDIR)
LFLAG = -L$(LIBFTDIR) -lft

MK = make -C
RM = rm -f

NAME = push_swap

all: $(NAME)
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(LFLAG) $^ -o $@
$(LIBFT):
	$(MK) $(LIBFTDIR)
	$(MK) $(LIBFTDIR) bonus
%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@
clean:
	$(MK) $(LIBFTDIR) clean
	$(RM) $(OBJS)
fclean: clean
	$(MK) $(LIBFTDIR) fclean
	$(RM) $(NAME)
re: fclean all
