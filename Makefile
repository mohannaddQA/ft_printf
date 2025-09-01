NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar crs
RM = rm -f
LIBFT_DIR = libft
LIBFT_FILE = ${LIBFT_DIR}/libft.a
MAKEFLAGS += --no-print-directory

SHARED = ft_printf.c \
		 ft_print_functions.c \
		 ft_print_functions_2.c \
		 ft_utils.c \
		 ft_utils2.c

SRCS = ${SHARED} ft_parse_function.c

BONUS_SRCS = ${SHARED} ft_parse_function_bonus.c \
 						ft_handle_sequence_information_bonus.c \
						ft_printf_seq_diu_bonus.c \
						ft_printf_seq_sc_bonus.c \
						ft_printf_seq_x_bonus.c \
						ft_printf_seq_p_bonus.c
						
OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} $(LIBFT_FILE)
	@cp ${LIBFT_FILE} ${NAME}
	@${AR} ${NAME} ${OBJS}

bonus: ${BONUS_OBJS} $(LIBFT_FILE)
	@cp ${LIBFT_FILE} ${NAME}
	@${AR} ${NAME} ${BONUS_OBJS}

%.o: %.c 
	@$(CC) ${CFLAGS} -c $< -o $@

$(LIBFT_FILE): $(LIBFT_DIR)
	@make all -C $(LIBFT_DIR)

clean: 
	@make clean -C ${LIBFT_DIR}
	@${RM} ${OBJS} ${BONUS_OBJS}
	
fclean: clean
	@make fclean -C ${LIBFT_DIR}
	@${RM} ${NAME}
	
re: fclean all

.PHONY: all bonus clean fclean re
