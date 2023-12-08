BLUE			:= $(shell tput setaf 4)
PASTEL_MAGENTA	:= $(shell tput setaf 213)
RESET			:= $(shell tput sgr0)

SRCS	= main.cpp\

INCL	= whatever.hpp\

OBJS	= ${SRCS:.cpp=.o}

NAME	= whatever

CC		= c++

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic


.c.o:
			@${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

${NAME}:	${OBJS} ${INCL}
			@${CC} ${CFLAGS} -o ${NAME} ${OBJS}
			@echo "${BLUE} Compilation ${NAME} done ${RESET}"

all:		${NAME}

clean:
			@${RM} ${OBJS}
			@rm -f *_shrubbery
			@echo "${BLUE} Clean object files done ${RESET}"

fclean:		clean
			@${RM} ${NAME}
			@echo "${BLUE} Clean ${NAME} done ${RESET}"

re:			fclean all

.PHONY: 	all clean fclean re