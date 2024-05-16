RM		= rm -rf
CPP		= c++
CFLAG	= -std=c++98 -Wall -Wextra -Werror
SRCS	= main.cpp \
		  Span.cpp
OBJS	= $(SRCS:.cpp=.o)
NAME	= ex01

.PHONY: all clean fclean re
all		: $(NAME)
clean	:
	$(RM) $(OBJS)
fclean	: clean
	$(RM) $(NAME)
re		: fclean all

$(NAME)	: $(OBJS)
	$(CPP) $(CFLAG) -o $(NAME) $(OBJS)
%.o		: %.cpp
	$(CPP) $(CFLAG) $< -o $@ -c