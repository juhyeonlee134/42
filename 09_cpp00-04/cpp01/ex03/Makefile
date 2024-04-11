RM = rm -rf
CPP = c++
CFLAG = -std=c++98 -Wall -Werror -Wextra
SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS = ${SRCS:.cpp=.o}
NAME = violence

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
