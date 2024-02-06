RM		= rm -rf
CPP		= c++
CFLAG	= -std=c++98 -Wall -Wextra -Werror
SRC		= megaphone.cpp
OBJ		= ${SRC:.cpp=.o}
NAME	= megaphone

.PHONY	: all clean fclean re
all		: ${NAME}
clean	:
	${RM} ${OBJ}
fclean	: clean
	${RM} ${NAME}
re		: fclean all

${NAME}	: ${OBJ}
	${CPP} ${OBJ} -o ${NAME}
%.o		: %.cpp
	${CPP} ${CFLAG} $< -o $@ -c
