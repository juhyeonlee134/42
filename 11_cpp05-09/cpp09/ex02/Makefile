RM		= rm -rf
CPP		= c++
CFLAG	= -Wall -Wextra -Werror -std=c++98
SRCS	= main.cpp PmergeMe.cpp
OBJS	= $(SRCS:.cpp=.o)
NAME	= PmergeMe

.PHONY	: all clean fclean re
all		: $(NAME)
clean	:
	$(RM) $(OBJS)
fclean	: clean
	$(RM) $(NAME)
re		: fclean all

$(NAME)	: $(OBJS)
	$(CPP) $(CFLAG) -o $(NAME) $(OBJS)
%.o		: %.cpp
	$(CPP) $(CFLAG) -c $< -o $@