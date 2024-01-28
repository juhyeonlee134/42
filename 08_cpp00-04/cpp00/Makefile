RM		= rm -rf
CPP		= c++
CFLAG	= -std=c++98 -Wall -Wextra -Werror
SRCS	= megaphone.cpp 
OBJS	= ${SRCS:.cpp = .o}
NAME	= megaphone

.PHONY	= all clean fclean re

all		: ${NAME}
clean	:
	${RM} ${OBJS}
fclean	: clean
	${RM} ${NAME}
re		: fclean all

${NAME}	: ${OBJS}
	${CPP} ${OBJS} -o ${NAME}
%.o		: %.cpp
	${CPP} ${CFLAG} $< -o $@ -c
