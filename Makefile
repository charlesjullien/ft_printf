.PHONY: all clean fclean re

CC = gcc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
INC = -I./includes
SRCS =			srcs/ft_printf.c \
				srcs/ft_printf_utils.c \
				srcs/ft_printf_utils2.c \
				srcs/print_c.c \
				srcs/print_s.c \
				srcs/print_d_or_i.c \
				srcs/print_u.c \
				srcs/print_x.c \
				srcs/print_p.c \
				srcs/print_pct.c
OBJS = 			${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c ${INC} $< -o ${<:.c=.o}

${NAME}: ${LIBFT} ${OBJS}
	ar rc ${NAME} ${OBJS} $(shell find libft -name '*.o')
	ranlib ${NAME}

${LIBFT}:
	@make all -C libft

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	@make clean -C libft
	rm -f ${NAME}
	rm -f ${LIBFT}

re: fclean all
