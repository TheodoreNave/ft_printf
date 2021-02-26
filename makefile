NAME			= libftprintf.a

SRCS_LIST		= \
					ft_printf.c \
					ft_strrev.c \
                                        ft_putchar.c \
                                        ft_putstr.c \
                                        ft_strlen.c \
					ft_printf_utils.c \
                                        ft_itoa_base.c \
                                        ft_display_str.c \
                                        ft_display_ptr.c \
                                        ft_display_int.c \
                                        ft_display_hex.c \
                                        ft_display_char.c \
                                        ft_display_modu.c

SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})

OBJS			= ${SRCS:.c=.o}

HEADER			= includes
FOLDER			= srcs

CC				= gcc
CFLAGS 			= -Wall -Wextra -Werror
RM				= rm -f

all:			${NAME}

$(NAME):		${OBJS}
				@ar -rcs ${NAME} ${OBJS}

bonus:			${NAME}

%.o: %.c
				@${CC} ${CFLAGS} -I ${HEADER} -o $@ -c $<

clean:
				@${RM} ${OBJS}

fclean:			clean
				@${RM} ${NAME}

re:				fclean all

.PHONY: 		all fclean clean re