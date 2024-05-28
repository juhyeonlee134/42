RM		= rm -rf
CPP		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
SRCS	= main.cpp PmergeMe.cpp
OBJS	= $(SRCS:.cpp=.o)
NAME	= ex02

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