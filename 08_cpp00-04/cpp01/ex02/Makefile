RM = rm -rf
CPP = c++
CFLAG = -std=c++98 -Wall -Werror -Wextra
SRCS = main.cpp
OBJS = ${SRCS:.cpp=.o}
NAME = hi

.PHONY : all clean fclean re
all : ${NAME}
clean :
	${RM} ${OBJS}
fclean : clean
	${RM} ${NAME}
re : fclean all

${NAME} : ${OBJS}
	${CPP} ${OBJS} -o ${NAME}
%.o : %.cpp
	${CPP} ${CFLAG} $< -o $@ -c