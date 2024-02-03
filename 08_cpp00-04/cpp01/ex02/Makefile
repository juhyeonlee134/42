RM		= rm -rf
CPP		= c++
CFLAG	= -std=c++98 -Wall -Wextra -Werror
SRC		= main.cpp
OBJ		= ${SRC:.cpp=.o}
NAME	= HI_THIS_IS_BRAIN

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