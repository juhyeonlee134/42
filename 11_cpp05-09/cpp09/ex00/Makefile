RM		= rm -rf 
CPP		= c++
CFLAG	= -std=c++98 -Wall -Wextra -Werror -g3
SRCS	= main.cpp BitcoinExchange.cpp
OBJS	= ${SRCS:.cpp=.o}
NAME	= btc

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