CLIENT_SRC = srcs/client.c
SERVER_SRC = srcs/server.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

INCDIR = includes

MK = make -C
RM = rm -rf

CC = cc
CFLAG = -Wall -Wextra -Werror -I$(INCDIR) -c

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a
FTPRINTFDIR = ft_printf
FTPRINTF = $(FTPRINTFDIR)/libftprintf.a

LFLAG = -L$(LIBFTDIR) -lft -L$(FTPRINTFDIR) -lftprintf

NAME = minitalk
CLIENT_NAME = client
SERVER_NAME = server

all : $(NAME)

$(NAME) : $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME) : $(SERVER_OBJ) $(FTPRINTF) $(LIBFT)
	$(CC) $(LFLAG) $^ -o $@

$(CLIENT_NAME) : $(CLIENT_OBJ) $(FTPRINTF) $(LIBFT)
	$(CC) $(LFLAG) $^ -o $@

$(FTPRINTF) :
	$(MK) $(FTPRINTFDIR)

$(LIBFT) :
	$(MK) $(LIBFTDIR)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

clean :
	$(MK) $(LIBFTDIR) clean
	$(MK) $(FTPRINTFDIR) clean
	$(RM) $(PRINTF_OBJS) $(CLIENT_OBJ) $(SERVER_OBJ)

fclean : clean
	$(MK) $(LIBFTDIR) fclean
	$(MK) $(FTPRINTFDIR) fclean
	$(RM) $(CLIENT_NAME) $(SERVER_NAME)

re : fclean all
