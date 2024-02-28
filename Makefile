NAME = ft_ls

SRCS = src/main.c \
		src/utils.c

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:	${NAME}

clean:
	@rm -rf ${OBJS}

fclean:	clean
	@rm -rf ${NAME}

re:	fclean all