RM		= rm -rf
CPP		= c++
CFLAG	= -std=c++98 -Wall -Wextra -Werror
SRCS	= main.cpp \
		  Zombie.cpp \
		  zombieHorde.cpp
OBJS	= ${SRCS:.cpp=.o}
NAME	= Zombie

.PHONY	: all clean fclean re
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