BLUE			:= $(shell tput setaf 4)
PASTEL_MAGENTA	:= $(shell tput setaf 213)
RESET			:= $(shell tput sgr0)

SRCS	= main.cpp\
		  AMateria.cpp\
		  Character.cpp\
		  MateriaSource.cpp\
		  Ice.cpp\
		  Cure.cpp\

INCL	= AMateria.hpp\
		ICharacter.hpp\
		Character.hpp\
		IMateriaSource.hpp\
		MateriaSource.hpp\
		Ice.hpp\
		Cure.hpp\

OBJS	= ${SRCS:.cpp=.o}

NAME	= weird_exercise

CC		= c++

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -std=c++98 #-g3 -fsanitize=address


.c.o:
			@${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

${NAME}:	${OBJS} ${INCL}
			@${CC} ${CFLAGS} -o ${NAME} ${OBJS}
			@echo "${BLUE} Compilation ${NAME} done ${RESET}"

all:		${NAME}

clean:
			@${RM} ${OBJS}
			@echo "${BLUE} Clean object files done ${RESET}"

fclean:		clean
			@${RM} ${NAME}
			@echo "${BLUE} Clean ${NAME} done ${RESET}"

re:			fclean all

.PHONY: 	all clean fclean re
