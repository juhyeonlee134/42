RM		= rm -rf
CPP		= c++
CFLAG	= -Wall -Wextra -Werror
SRCS	= Bureaucrat.cpp \
		  main.cpp
OBJS	= ${SRCS:.cpp=.o}
NAME	= ex00

.PHONY	: all clean fclean re

all		: ${NAME}
clean	:
	${RM} ${OBJS}
fclean	: clean
	${RM} ${NAME}
re		: fclean all

${NAME}	: ${OBJS}
	${CPP} $^ -o $@
%.o		: %.cpp
	${CPP} ${CFLAG} $< -o $@ -c
