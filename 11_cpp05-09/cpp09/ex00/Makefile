RM		= rm -rf
CPP		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
SRCS	= main.cpp BitcoinExchange.cpp
OBJS	= $(SRCS:.cpp=.o)
NAME	= btc

.PHONY: all clean fclean re
all		: $(NAME)
clean	:
	$(RM) $(OBJS)
fclean	: clean
	$(RM) $(NAME)
re		: fclean all

$(NAME)	: $(OBJS)
	$(CPP) $(CFLAGS) -o $(NAME) $(OBJS)
%.o		: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@