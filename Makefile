# COLORS
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

# SYMBOLS
INFO = $(WHITE)[$(BLUE)ℹ️$(WHITE)] $(NOP)
SUCCESS = $(WHITE)[$(GREEN)✅$(WHITE)] $(GREEN)
WARNING = $(WHITE)[$(YELLOW)⚠️$(WHITE)] $(YELLOW)
ERROR = $(WHITE)[$(RED)❌$(WHITE)] $(RED)

NAME = push_swap

NAME_BNS = checker

CC = cc

SRCS =	./main.c							\
		./big_sort.c						\
		./back_to_A.c						\
		./rules/reverse_rotate.c			\
		./rules/rotate.c					\
		./rules/swap.c						\
		./rules/push.c						\
		./push_sort.c						\
		./checker_input/input_checker.c		\
		./push_swap_utils/check_input_utils.c\
		./push_swap_utils/check_input_utils1.c\
		./push_swap_utils/check_input_utils2.c\
		./push_swap_utils/check_input_utils3.c\
		./push_swap_utils/check_input_utils4.c\
		./push_swap_utils/check_input_utils5.c\
		./libft/ft_memset.c					\
		./libft/ft_memchr.c					\
		./libft/ft_memmove.c		\
		./libft/ft_memcmp.c			\
		./libft/ft_memcpy.c			\
		./libft/ft_bzero.c			\
		./libft/ft_atoi.c			\
		./libft/ft_strlen.c			\
		./libft/ft_strlcpy.c		\
		./libft/ft_strchr.c			\
		./libft/ft_strrchr.c		\
		./libft/ft_strnstr.c		\
		./libft/ft_strcmp.c			\
		./libft/ft_isalnum.c		\
		./libft/ft_strlcat.c		\
		./libft/ft_isdigit.c		\
		./libft/ft_isalpha.c		\
		./libft/ft_isascii.c		\
		./libft/ft_isprint.c		\
		./libft/ft_tolower.c		\
		./libft/ft_toupper.c		\
		./libft/ft_calloc.c			\
		./libft/ft_strdup.c			\
		./libft/ft_substr.c			\
		./libft/ft_strjoin.c		\
		./libft/ft_strtrim.c		\
		./libft/ft_split.c			\
		./libft/ft_itoa.c			\
		./libft/ft_strmapi.c		\
		./libft/ft_putstr_fd.c		\
		./libft/ft_putendl_fd.c		\
		./libft/ft_putnbr_fd.c		\
		./libft/ft_putchar_fd.c		\
		./libft/ft_striteri.c 		\


SRCS_BNS = 	./bonus/main_bonus.c 		\
			./bonus/input_check.c 		\
			./bonus/bonus_utils.c		\
			./bonus/bonus_utils_v1.c	\
			./bonus/bonus_utils_v2.c	\
			./bonus/bonus_utils_v3.c	\
			./libft/ft_memset.c			\
			./libft/ft_memchr.c			\
			./libft/ft_memmove.c		\
			./libft/ft_memcmp.c			\
			./libft/ft_memcpy.c			\
			./libft/ft_bzero.c			\
			./libft/ft_atoi.c			\
			./libft/ft_strlen.c			\
			./libft/ft_strlcpy.c		\
			./libft/ft_strchr.c			\
			./libft/ft_strrchr.c		\
			./libft/ft_strnstr.c		\
			./libft/ft_strcmp.c			\
			./libft/ft_isalnum.c		\
			./libft/ft_strlcat.c		\
			./libft/ft_isdigit.c		\
			./libft/ft_isalpha.c		\
			./libft/ft_isascii.c		\
			./libft/ft_isprint.c		\
			./libft/ft_tolower.c		\
			./libft/ft_toupper.c		\
			./libft/ft_calloc.c			\
			./libft/ft_strdup.c			\
			./libft/ft_substr.c			\
			./libft/ft_strjoin.c		\
			./libft/ft_strtrim.c		\
			./libft/ft_split.c			\
			./libft/ft_itoa.c			\
			./libft/ft_strmapi.c		\
			./libft/ft_putstr_fd.c		\
			./libft/ft_putendl_fd.c		\
			./libft/ft_putnbr_fd.c		\
			./libft/ft_putchar_fd.c		\
			./libft/ft_striteri.c 		\
			./libft/get_next_line.c		\
			./rules/reverse_rotate.c	\
			./rules/rotate.c			\
			./rules/swap.c				\
			./rules/push.c				\

OBJ_BNS = ${SRCS_BNS:.c=.o}
OBJ = ${SRCS:.c=.o}

all : ${NAME}
${NAME} : ${OBJ}
		@echo "$(SUCCESS)Objects folder created successfully$(NOC)"
		cc ${CFLAGS} $(OBJ) -o $(NAME)
		@echo "$(INFO)Building $(NAME)...$(NOC)"
		@echo "$(SUCCESS)Libft library built successfully!$(NOC)"

bonus : ${NAME_BNS}
${NAME_BNS} : ${OBJ_BNS}
		@echo "$(SUCCESS)Bonus Objects folder created successfully$(NOC)"
		cc ${CFLAGS} $(OBJ_BNS) -o $(NAME_BNS)
		@echo "$(INFO)Building $(NAME_BNS)...$(NOC)"
		@echo "$(SUCCESS)Bonus Libft library built successfully!$(NOC)"

clean:
	make clean -C ./libft
	rm -f $(OBJ_BNS)
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME_BNS)
	rm -f $(NAME)

re: fclean all


# all: $(NAME)

# $(NAME): $(SRC)
# 	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

# bonus: $(SRC_B)
# 	$(CC) $(CFLAGS) $(SRC_B) -o $(NAME_B)
